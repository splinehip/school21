#pragma once
#include <iostream>

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;

public:
    ASpell(void){};
    ASpell(const std::string &name, const  std::string &effects);
    ASpell(const ASpell &inst);
    virtual ~ASpell(void){};

    ASpell  &operator=(const ASpell &inst);

    std::string getName(void) const;
    std::string getEffects(void) const;
    virtual ASpell  *clone(void) const = 0;
    void    launch(const ATarget &atarget);
};

#include "ATarget.hpp"
