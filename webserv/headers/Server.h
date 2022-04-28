/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:25:38 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/28 11:31:04 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Config.h"
#include "logger/Log.h"

class Server
{
private:
    cfg::Config  cfg;

public:
    Server(char **argv);
    ~Server(void);
};
