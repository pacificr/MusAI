#pragma once

#include "Timeline.h"

class IPitchRule
{
  public:
    virtual ~IPitchRule() = default;
    virtual void applyPitches(Timeline&, std::string) const;
};
