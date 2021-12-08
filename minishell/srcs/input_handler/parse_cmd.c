/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:33:02 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/08 13:32:26 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "builtins.h"
#include "input_handler.h"

static inline void	set_actions(t_actions *t_actions, char **s_cmd)
{
	int	i;
	int	j;

	(void)t_actions;
	i = 0;
	while (s_cmd[i])
	{
		if (ft_strchr(s_cmd[i], quote))
		{
			j = i + 1;
			while (s_cmd[j])
			{
				if (ft_strrchr(s_cmd[j], quote))
					break ;
				j++;
			}
			while (s_cmd[j] && i <= j)
				ft_printf("%s ", s_cmd[i++]);
			if (s_cmd[j])
				ft_printf("\n");
		}
		if (s_cmd[i])
			ft_printf("%s\n", s_cmd[i++]);
	}
}

t_actions	*parse_cmd(char *cmd, char **env)
{
	int			i;
	char		**s_cmd;
	t_actions	*actions;

	(void)env;
	actions = NULL;
	cmd = expand_vars(cmd, env);
	if (cmd == NULL)
	{
		ft_printf("Expanding var error.\n");
		return (actions);
	}
	ft_printf("EXPANDED CMD: '%s'\n", cmd);
	s_cmd = ft_split(cmd, ' ');
	if (s_cmd == NULL)
	{
		ft_printf("Spliting cdm error.\n");
		return (actions);
	}
	//set_actions(actions, s_cmd);
	free(cmd);
	i = 0;
	while (s_cmd[i])
		free(s_cmd[i++]);
	free(s_cmd);
	return (actions);
}
