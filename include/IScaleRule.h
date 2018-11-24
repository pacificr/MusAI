#pragma once

#include "IRule.h"

#include <vector>

class IScaleRule : public IRule
{
public:
  virtual ~IScaleRule() = default;
  virtual std::vector<int> getScaleDegrees() = 0;
};