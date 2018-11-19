#pragma once

#include "ISubdivisionRule.h"

class AbsoluteSubdivisionRule : public ISubdivisionRule
{
private:
  int mNotesPerBeat;
public:
  AbsoluteSubdivisionRule(int);
  void describe(RuleEnvironment&);
  double applyTiming(int);
};