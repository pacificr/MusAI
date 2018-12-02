#include "../include/AbsoluteTempoRule.h"

AbsoluteTempoRule::AbsoluteTempoRule(double bpm)
{
  mBpm = bpm;
}

void AbsoluteTempoRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addFulfillment("Tempo", this);
}

double AbsoluteTempoRule::applyTempo(double relativeBeat)
{
  return (60.0 / mBpm) * relativeBeat;
}