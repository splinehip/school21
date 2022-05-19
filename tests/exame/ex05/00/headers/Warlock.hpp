#pragma once
#include <string>
#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;

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
};
