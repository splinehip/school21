/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_err.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:35:02 by cflorind          #+#    #+#             */
/*   Updated: 2022/02/07 09:28:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_ERR_H
# define MSG_ERR_H
#
# define MSG_ERR "Error\n"
# define MSG_INVALARG "Invalid arguments number. \n Example: ./miniRT scene.rt\n"
# define MSG_ERRFILEEXT "Scene description file extention must be .rt\n"
# define MSG_NOTUNIQ "Capital letter defined elements must be uniq: A, C, L.\n"
# define MSG_ERRREAD "Something wrong during read scene file\n"
# define MSG_RESNULL "Res is null\n"
# define MSG_UNDEFID "Unknown indentifier for scene args\n"
# define MSG_INVSCENEARG "Invalid arguments number of scene element.\n"
# define MSG_INVALRANGE "Invalid range of arguments value.\n"

void	print_err(char *MSG);

#endif
