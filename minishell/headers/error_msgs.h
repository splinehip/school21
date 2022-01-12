/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:45:36 by lbaela            #+#    #+#             */
/*   Updated: 2022/01/12 11:34:36 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

# define ERR_ARGC				"minishell: There should be no arguments\n"
# define MSG_ERR_MEM			"minishell: Memory allocation failed\n"
# define MSG_ERR_PWD			"minishell: No pwd value\n"
# define MSG_ERR_CD				"minishell: cd: %s: "
# define MSG_ERR_HOME			"minishell: Home value is not defined\n"
# define MSG_ERR_CD_ARGS		"bash: cd: too many arguments\n"
# define MSG_ERR_ENV			"minishell: Can't duplicate env.\n"
# define MSG_ERR_SYNATX			"minishell: Syntax error\n"
# define MSG_ERR_CMD_UQ\
	"minishell: Syntax error: command has unclosed quotes `%c\'\n"
# define MSG_ERR_CMD_EEOF\
	"minishell: Syntax error: command has escaped EOF\n"
# define MSG_ERR_MORE2CNTRLS\
	"minishell: Syntax error: command has wrong number of `%c\'\n"
# define MSG_ERR_CMD_HAS_UP\
	"minishell: Syntax error: command has unclosed parenthesis\n"
# define MSG_ERR_CMD_PARSEERR	"minishell: Parse command unsucces\n"
# define MSG_ERR_CMD_NFOUND		"minishell: %s: command not found\n"
# define MSG_ERR_CMD_ISDIR		"minishell: %s: it`s a directory\n"
# define MSG_ERR_PIPE			"minishell: Pipes creation fail\n"
# define MSG_ERR_INVRDTYPE		"minishell: Invalide redirect type\n"
# define MSG_ERR_EXIT_NUM\
	"minishell: exit: %s: Numeric argument required\n"
# define MSG_ERR_EXIT_ARGS		"minishell: exit: Too many arguments\n"
# define MSG_ERR_INVAL_HIS_FD	"minishell: Invalid descriptor of history file\n"
# define MSG_ERR_INVAL_ENVNAME	"minishell: Invalid env name: %s\n"
# define MSG_ERR_HEREDOC\
	"minishell: warning: here-document delimited by end-of-file (wanted `%s\')\n"

#endif
