#pragma once
#include <string>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
    std::map<std::string, ASpell *>   book;

private:
    SpellBook(const SpellBook &inst);
    SpellBook   &operator=(const SpellBook &inst);

public:
    SpellBook(void);
    ~SpellBook(void);

    void    learnSpell(ASpell *spell);
    void    forgetSpell(const std::string &name);
    ASpell  *createSpell(const std::string &name);
};
