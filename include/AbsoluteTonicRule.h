#pragma once

#include "ITonicRule.h"

class AbsoluteTonicRule : public ITonicRule
{
private:
  int mTonic;
public:
  AbsoluteTonicRule(int);
  void describe(RuleEnvironment&);
  int applyTonic(int);
};