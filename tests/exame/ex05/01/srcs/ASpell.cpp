#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const  std::string &effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(const ASpell &inst)
{
    *this = inst;
}

ASpell  &ASpell::operator=(const ASpell &inst)
{
    this->name = inst.name;
    this->effects = inst.effects;
    return (*this);
}

std::string ASpell::getName(void) const
{
    return (this->name);
}

std::string ASpell::getEffects(void) const
{
    return (this->effects);
}

void    ASpell::launch(const ATarget &atarget)
{
    atarget.getHitBySpell(*this);
}
