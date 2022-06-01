#pragma once
#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
private:
    std::string name;
    std::string title;
    std::map<std::string, ASpell *> m_spells;

private:
    Warlock(void);
    Warlock(const Warlock &inst);

    Warlock &operator=(const Warlock &inst);

public:
    Warlock(const std::string &name, const std::string &titel);
    ~Warlock(void);

    const std::string   &getName(void);
    const std::string   &getTitle(void);
    void                setTitle(const std::string &title);
    void                introduce(void);
    void                learnSpell(ASpell *spell);
    void                forgetSpell(const std::string &name);
    void                launchSpell(const std::string &name, ATarget &target);
};
