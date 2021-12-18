/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:48:39 by cflorind          #+#    #+#             */
/*   Updated: 2021/12/18 15:24:34 by lbaela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PFX_MSG "\1\033[32m\2minishell:\1\033[33m\2"
# define POSFX_MSG "\1\033[32m$\033[39m\2 "
# define PROMPT "minishell$ "

int	main(int argc, char **argv, char **env);

#endif
