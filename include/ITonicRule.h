#pragma once

#include "IRule.h"

class ITonicRule : public IRule
{
public:
  virtual ~ITonicRule() = default;
  virtual int applyTonic(int) = 0;
};