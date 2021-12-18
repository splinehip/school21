/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_expand_template.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 03:50:51 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/18 03:52:00 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "bool.h"
#include "input_handler.h"

inline char	*do_expand_template(char *template_str)
{
	if (template_str == NULL)
		return (NULL);
	return (ft_strdup(template_str));
}
