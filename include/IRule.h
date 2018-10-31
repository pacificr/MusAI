#pragma once

#include "RuleEnvironment.h"

class IRule
{
public:
  virtual ~IRule() = default;
  virtual void describe(RuleEnvironment&) = 0;
};