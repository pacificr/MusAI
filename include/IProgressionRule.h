#pragma once

#include "Timeline.h"

class IProgressionRule
{
  public:
    virtual ~IProgressionRule() = default;
    virtual void applyChords(Timeline&, std::string) const = 0;
};
