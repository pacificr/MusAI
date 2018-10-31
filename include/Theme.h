#pragma once

#include "IRule.h"
#include "IGenerator.h"

class Theme
{
private:
  RuleEnvironment mRuleEnvironment;
public:
  void addRule(IRule&);
  IGenerator* getGenerator();
};