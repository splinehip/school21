/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:57:04 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/11 16:02:31 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "libft.h"
#include "builtins.h"
#include "minishell.h"

// void	ft_sort_string_tab(char **tab)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	i = 1;
// 	while (tab[i] != NULL && tab[0] != NULL)
// 	{
// 		j = i;
// 		while (j > 0 && ft_strcmp(tab[j - 1], tab[j]) > 0)
// 		{
// 			tmp = tab[j - 1];
// 			tab[j - 1] = tab[j];
// 			tab[j] = tmp;
// 			j--;
// 		}
// 		i++;
// 	}
// }

static void	update_end_of_str(char *name, char ch)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (name[i] == ch)
		{
			name[i] = 0;
			break ;
		}
		i++;
	}
}

void	add_new_env(char *str, char ***env)
{
	char	*name;
	char	*value;

	value = NULL;
	name = ft_strdup(str);
	update_end_of_str(name, eq);
	if (ft_strchr(str, eq))
		value = ft_strdup(ft_strchr(str, eq) + 1);
	printf("add_new_env: NAME: %s, VAL: %s\n", name, value);
	set_env(name, value, env);
	free(name);
	free(value);
}

int	do_export(t_action action, char ***env)
{
	int		fd;
	int		i;

	i = 1;
	fd = do_redirects_builtin(action);
	if (!action.exec.argv[i] && fd > 0)
	{
		i = 0;
		ft_sort_strs(env);
		while ((*env)[i])
		{
			write(fd, EXPORT_PREPEND, ft_strlen(EXPORT_PREPEND));
			write(fd, (*env)[i], ft_strlen((*env)[i]));
			write(fd, "\n", 1);
			i++;
		}
	}
	else
		while (action.exec.argv[i])
			add_new_env(action.exec.argv[i++], env);
	if (fd > 2)
		close(fd);
	return (0);
}
