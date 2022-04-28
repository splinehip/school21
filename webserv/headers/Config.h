/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cflorind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:51:35 by cflorind          #+#    #+#             */
/*   Updated: 2022/04/28 11:30:37 by cflorind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "logger/Log.h"

namespace cfg
{
class Config
{
private:
    const std::string   cfg_file;

public:
    Config(char **argv);
    ~Config(void);

    void    setDefCfg(void){};
    void    doParse(void);
};
}
