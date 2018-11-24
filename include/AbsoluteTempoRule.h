#pragma once

#include "ITempoRule.h"

class AbsoluteTempoRule : public ITempoRule
{
private:
  double mBpm;
public:
  AbsoluteTempoRule(double);
  void describe(RuleEnvironment&);
  double applyTempo(double);
};