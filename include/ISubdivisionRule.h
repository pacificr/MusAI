#pragma once

#include "IRule.h"

class ISubdivisionRule : public IRule
{
public:
  virtual ~ISubdivisionRule() = default;
  virtual double applyTiming(int) = 0;
};