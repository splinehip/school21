#pragma once
#include <iostream>

class ASpell;

class ATarget
{
protected:
    std::string type;

public:
    ATarget(const std::string &type);
    virtual ~ATarget(void){};

    const std::string &getType(void);
    virtual ATarget  *clone(void) const = 0;
    void getHitBySpell(const ASpell &aspell);
};

#include "ASpell.hpp"
