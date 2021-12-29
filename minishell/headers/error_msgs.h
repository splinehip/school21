/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:45:36 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/29 13:44:09 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

# define ERR_ARGC				"minishell: there should be no arguments\n"
# define MSG_ERR_MEM			"Memory allocation failed"
# define MSG_ERR_PWD			"No pwd value"
# define MSG_ERR_CMD_UQ			"Syntax error: command has unclosed quotes"
# define MSG_ERR_CMD_EEOF		"Syntax error: command has escaped EOF"
# define MSG_ERR_MORE2CNTRLS\
	"Syntax error: command has wrong number of"
# define MSG_ERR_CMD_HAS_UP\
	"Syntax error: command has unclosed parenthesis"
# define MSG_ERR_CMD_NFOUND		"minishel: %s: command not found\n"
# define MSG_ERR_CMD_ISDIR		"minishel: %s: it`s a directory\n"

#endif
