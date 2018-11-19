#pragma once

#include "IRule.h"

class ITempoRule : public IRule
{
public:
  virtual ~ITempoRule() = default;
  virtual double applyTempo(double) = 0;
};