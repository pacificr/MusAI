#include "../include/AbsoluteSubdivisionRule.h"

AbsoluteSubdivisionRule::AbsoluteSubdivisionRule(int notesPerBeat)
{
  mNotesPerBeat = notesPerBeat;
}

void AbsoluteSubdivisionRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Subdivision", this);
}

double AbsoluteSubdivisionRule::applyTiming(int subdivision)
{
  return subdivision * (1 / (double)mNotesPerBeat);
}