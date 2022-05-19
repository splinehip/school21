#include "SpellBook.hpp"

SpellBook::SpellBook(void){}

SpellBook::~SpellBook(void)
{
    std::map<std::string, ASpell *>::iterator    it;
    for (it = this->book.begin(); it != this->book.end(); ++it)
    {
        delete it->second;
    }
}

void    SpellBook::learnSpell(ASpell *spell)
{
    if (spell == NULL)
        return ;
    if (this->book.find(spell->getName()) != this->book.end())
    {
        delete this->book[spell->getName()];
    }
    this->book[spell->getName()] = spell->clone();
}

void    SpellBook::forgetSpell(const std::string &name)
{
    if (this->book.find(name) != this->book.end())
    {
        delete this->book[name];
        this->book.erase(name);
    }
}

ASpell  *SpellBook::createSpell(const std::string &name)
{
    if (this->book.find(name) != this->book.end())
    {
        return (this->book[name]);
    }
    return (NULL);
}
