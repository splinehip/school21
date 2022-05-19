#include "ATarget.hpp"

ATarget::ATarget(const std::string &type)
{
    this->type = type;
}

ATarget::ATarget(const ATarget &inst)
{
    *this = inst;
}

ATarget  &ATarget::operator=(const ATarget &inst)
{
    this->type = inst.type;
    return (*this);
}

const std::string &ATarget::getType(void)
{
    return (this->type);
}

void ATarget::getHitBySpell(const ASpell &aspell) const
{
    std::cout << this->type << " has been " << aspell.getEffects() << "!"
        << std::endl;
}
