#pragma once

#include "ITempoRule.h"

class AbsoluteTempoRule : public ITempoRule
{
private:
  int mBpm;
public:
  AbsoluteTempoRule(double);
  void describe(RuleEnvironment&);
  double applyTempo(double);
};