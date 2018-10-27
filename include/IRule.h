#pragma once

#include "RuleEnvironment.h"

#include <memory>

class IRule
{
protected:
  std::shared_ptr<RuleEnvironment> mRuleEnvironment;
public:
  IRule(const RuleEnvironment&);
  //virtual ~IRule() = 0;
};