#pragma once
#include "ASpell.hpp"

class Fwoosh: public ASpell
{
public:
    Fwoosh(void);
    ~Fwoosh(void);

    ASpell  *clone(void) const;
};

