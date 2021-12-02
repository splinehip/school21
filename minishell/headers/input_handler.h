/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/02 16:21:37 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H

typedef enum e_controls	t_controls;

typedef enum e_controls
{
	quote = (int)'"',
	single_quote = (int)'\'',
	left_corner = (int)'<',
	right_corner = (int)'>',
	pipes = (int)'|',
	env_var = (int)'$'
}	t_controls;

int		input_handler(void);
void	test_func(void);

#endif
