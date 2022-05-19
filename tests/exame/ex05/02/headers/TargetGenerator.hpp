#pragma once
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
private:
    std::map<std::string, ATarget *>    targets;

private:
    TargetGenerator(const TargetGenerator &inst);
    TargetGenerator &operator=(const TargetGenerator &inst);

public:
    TargetGenerator(void);
    ~TargetGenerator(void);

    void    learnTargetType(ATarget *target);
    void    forgetTargetType(const std::string &name);
    ATarget *createTarget(const std::string &name);
};
