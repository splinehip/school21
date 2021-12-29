/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:06:21 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/28 13:57:32 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum						e_controls;
enum						e_actions;
enum						e_builtins;
enum						e_redirects;
enum						e_direction;

enum e_controls
{
	quote			= (int)'"',
	single_quote	= (int)'\'',
	left_corner		= (int)'<',
	right_corner	= (int)'>',
	open_parenth	= (int)'(',
	close_parenth	= (int)')',
	escape			= (int)'\\',
	slash			= (int)'/',
	pipes			= (int)'|',
	colon			= (int)':',
	eq				= (int)'=',
	question		= (int)'?',
	dollar			= (int)'$',
	ampersand		= (int)'&',
	underscore		= (int)'_',
	space			= (int)' ',
	asterisk		= (int)'*',
	dot				= (int)'.',
	tab				= (int)'\t',
	endl			= (int)'\n',
	vtab			= (int)'\v',
	cr				= (int)'\r',
	ends			= (int)'\0',
};

enum e_actions
{
	builtin,
	execute,
};

enum e_builtins
{
	echo,
	cd,
	pwd,
	export,
	unset,
	env,
	exit_built,
};

enum e_redirects
{
	input,
	output,
	read_input,
	output_append,
};

enum e_direction
{
	single_asterisk,
	all_inn_all,
	only_start,
	only_end,
	all_end,
	start_all,
	start_all_end,
};

typedef enum e_logic
{
	and		= (int)'&',
	or		= (int)'|'
}	t_logic;

#endif
