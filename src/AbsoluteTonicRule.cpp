#include "../include/AbsoluteTonicRule.h"

AbsoluteTonicRule::AbsoluteTonicRule(int tonic)
{
  mTonic = tonic;
}

void AbsoluteTonicRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Tonic", this);
}

int AbsoluteTonicRule::applyTonic(int pitch)
{
  return mTonic + pitch;
}