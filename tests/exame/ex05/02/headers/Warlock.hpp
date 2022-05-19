#pragma once
#include <string>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
    std::string name;
    std::string title;
    SpellBook   book;

public:
    Warlock();
    Warlock(const std::string &name, const std::string &titel);
    Warlock(const Warlock &inst);
    ~Warlock(void);

    Warlock &operator=(const Warlock &inst);

    const std::string   &getName(void) const;
    const std::string   &getTitle(void) const;
    void                setTitle(const std::string &title);
    void                introduce(void) const;
    void                learnSpell(ASpell *spell);
    void                forgetSpell(const std::string &name);
    void                launchSpell(const std::string &name,
                                        const ATarget &target);
};
