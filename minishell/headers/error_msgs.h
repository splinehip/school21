/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:45:36 by lbaela            #+#    #+#             */
/*   Updated: 2021/12/30 11:40:43 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

# define ERR_ARGC				"minishell: there should be no arguments\n"
# define MSG_ERR_MEM			"minishell: Memory allocation failed\n"
# define MSG_ERR_PWD			"minishell: No pwd value\n"
# define MSG_ERR_SYNATX			"minishell: syntax error\n"
# define MSG_ERR_CMD_UQ\
	"minishell: Syntax error: command has unclosed quotes `%c\'\n"
# define MSG_ERR_CMD_EEOF\
	"minishell: Syntax error: command has escaped EOF\n"
# define MSG_ERR_MORE2CNTRLS\
	"minishell: Syntax error: command has wrong number of `%c\'\n"
# define MSG_ERR_CMD_HAS_UP\
	"minishell: Syntax error: command has unclosed parenthesis\n"
# define MSG_ERR_CMD_PARSEERR	"minishell: parse command unsucces\n"
# define MSG_ERR_CMD_NFOUND		"minishell: %s: command not found\n"
# define MSG_ERR_CMD_ISDIR		"minishell: %s: it`s a directory\n"
# define MSG_ERR_PIPE			"minishell: pipes creation fail\n"

#endif
