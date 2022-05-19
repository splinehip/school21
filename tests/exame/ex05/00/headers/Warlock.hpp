#pragma once
#include <string>
#include <iostream>

class Warlock
{
private:
    std::string name;
    std::string title;

private:
    Warlock(void);
    Warlock(const Warlock &inst);

    Warlock &operator=(const Warlock &inst);

public:
    Warlock(const std::string &name, const std::string &titel);
    ~Warlock(void);

    const std::string   &getName(void) const;
    const std::string   &getTitle(void) const;
    void                setTitle(const std::string &title);
    void                introduce(void) const;
};
