#pragma once
#include <iostream>

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;

public:
    ASpell(const std::string &name, const  std::string &effects);
    virtual ~ASpell(void){};

    std::string getName(void);
    std::string getEffects(void) const;
    virtual ASpell  *clone(void) const = 0;
    void    launch(ATarget &atarget);
};

#include "ATarget.hpp"
