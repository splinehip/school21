/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_do_select_template.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:20:44 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/20 17:22:36 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "input_handler.h"

inline void	do_select_template(char *res, t_select *args)
{
	if (*res == asterisk && ft_strlen(res) == 1)
		args->direction = single_asterisk;
	else if (*res == asterisk && res[ft_strlen(res) - 1] == asterisk)
		args->direction = all_inn_all;
	else if (*res == asterisk && ft_strchr(res + 1, asterisk) == NULL)
		args->direction = only_end;
	else if (res[ft_strlen(res) - 1] == asterisk
		&& ft_strchr(res, asterisk) == res + (ft_strlen(res) - 1))
		args->direction = only_start;
	else if (*res == asterisk)
		args->direction = all_end;
	else
		args->direction = start_all_end;
}
