#pragma once
#include "ATarget.hpp"

class Dummy: public ATarget
{
public:
    Dummy(void);
    ~Dummy();

    ATarget *clone(void) const;
};
