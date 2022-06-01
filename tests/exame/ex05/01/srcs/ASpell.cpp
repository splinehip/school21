#include "ASpell.hpp"

ASpell::ASpell(const std::string &name, const  std::string &effects)
{
    this->name = name;
    this->effects = effects;
}

std::string ASpell::getName(void)
{
    return (this->name);
}

std::string ASpell::getEffects(void) const
{
    return (this->effects);
}

void    ASpell::launch(ATarget &atarget)
{
    atarget.getHitBySpell(*this);
}
