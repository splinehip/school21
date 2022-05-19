#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void){}

TargetGenerator::~TargetGenerator(void)
{
    std::map<std::string, ATarget *>::iterator    it;
    for (it = this->targets.begin(); it != this->targets.end(); ++it)
    {
        delete it->second;
    }
}

void    TargetGenerator::learnTargetType(ATarget *target)
{
    if (target == NULL)
        return ;
    if (this->targets.find(target->getType()) != this->targets.end())
    {
        delete this->targets[target->getType()];
    }
    this->targets[target->getType()] = target->clone();
}

void    TargetGenerator::forgetTargetType(const std::string &name)
{
    if (this->targets.find(name) != this->targets.end())
    {
        delete this->targets[name];
        this->targets.erase(name);
    }
}

ATarget  *TargetGenerator::createTarget(const std::string &name)
{
    if (this->targets.find(name) != this->targets.end())
    {
        return (this->targets[name]);
    }
    return (NULL);
}
