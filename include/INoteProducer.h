#pragma once

#include "IRule.h"
#include "Note.h"

#include <vector>

class INoteProducer : public IRule
{
public:
    INoteProducer(const RuleEnvironment& re) : IRule(re){};
    virtual std::vector<Note> getNotes() = 0;
};