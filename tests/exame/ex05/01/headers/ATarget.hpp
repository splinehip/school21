#pragma once
#include <iostream>

class ASpell;

class ATarget
{
protected:
    std::string type;

public:
    ATarget(void){};
    ATarget(const std::string &type);
    ATarget(const ATarget &inst);
    virtual ~ATarget(void){};

    ATarget  &operator=(const ATarget &inst);

    const std::string &getType(void);
    virtual ATarget  *clone(void) const = 0;
    void getHitBySpell(const ASpell &aspell) const;
};

#include "ASpell.hpp"
