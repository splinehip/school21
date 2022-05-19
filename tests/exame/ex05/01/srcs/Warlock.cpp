#include "Warlock.hpp"

Warlock::Warlock(const std::string &_name, const std::string &_titel)
    : name(_name), title(_titel)
{
    std::cout << this->name << ": This looks like another boring day."
        << std::endl;
}

Warlock::~Warlock(void)
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
}

const std::string   &Warlock::getName(void) const
{
    return (this->name);
}

const std::string   &Warlock::getTitle(void) const
{
    return (this->title);
}

void                Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

void                Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title
        << std::endl;
}

void    Warlock::learnSpell(ASpell *spell)
{
    this->m_spells[spell->getName()] = spell;
}
void    Warlock::forgetSpell(const std::string &name)
{
    if (this->m_spells.find(name) != this->m_spells.end())
    {
        this->m_spells.erase(this->m_spells.find(name));
    }
}

void    Warlock::launchSpell(const std::string &name, const ATarget &target)
{
    if (this->m_spells.find(name) != this->m_spells.end())
    {
        this->m_spells.find(name)->second->launch(target);
    }
}
