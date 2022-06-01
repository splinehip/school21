#include "ATarget.hpp"

ATarget::ATarget(const std::string &type)
{
    this->type = type;
}

const std::string &ATarget::getType(void)
{
    return (this->type);
}

void ATarget::getHitBySpell(const ASpell &aspell)
{
    std::cout << this->type << " has been " << aspell.getEffects() << "!"
        << std::endl;
}
