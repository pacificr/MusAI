#pragma once

#include "IRule.h"

class IBuilder : public IRule
{
public:
  virtual ~IBuilder() = default;
  virtual IRule *build(RuleEnvironment&) = 0;
};