/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:25:16 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/27 12:08:40 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLER_H
# define INPUT_HANDLER_H
# define BUF_SIZE 1024
# include "enums.h"

typedef struct s_select		t_select;
typedef struct s_extract	t_extract;
typedef struct s_iter		t_iter;

typedef struct s_select
{
	int		j;
	int		direction;
	char	**templated_strs;
	char	*d_name;
	char	*res;
	char	buf[BUF_SIZE];
}	t_select;

typedef struct s_extract
{
	int		j;
	int		start;
	int		end;
	int		prev_end;
	char	*res;
	char	*pchar;
	char	buf[BUF_SIZE];
}	t_extract;

typedef struct s_iter
{
	int		i;
	int		j;
	int		l;
	int		k;
	int		init_res;
	int		in_qoutes;
	char	buf[BUF_SIZE];
	char	*name;
	char	*value;
	char	*res;
}	t_iter;

int			input_handler(char *cmd, char **env);
char		*parse_cmd(char *cmd, char **env, int type);
int			check_cmd_sequenses(char *cmd);
char		has_opened_quotes(char *cmd, int start, int end);
char		*do_parse(char *cmd, char **env);
char		*do_parse_whith_asterisk(char *cmd, char **env);
void		do_check_quotes(char *cmd, t_iter *iter);
int			escaped(char *cmd, int i);
int			do_expand_env(char *cmd, t_iter *iter, char **env);
char		*do_expand_template(char *template_str, char **env);
int			do_update_buf(char **res, char *str, char *buf, int *j);
int			do_drop_buf(char **res, char *buf, int *j);
void		get_template_border(char *cmd, t_extract *args);
char		*get_d_name(char **env);
void		do_select_template(char *res, t_select *args);
int			pattern_matched(t_select *args);
void		pattern_matching_get_next(char **next, char *templated_str);
int			do_match_all_inn_all(t_select *args);
int			do_match_only(t_select *args, int type);
int			do_match_all_end(t_select *args);
int			do_match_start_all(t_select *args);
int			do_match_start_all_end(t_select *args);

#endif
