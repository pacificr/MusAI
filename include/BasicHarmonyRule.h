#pragma once

#include "IRelativeNoteRule.h"

class BasicHarmonyRule : public IRelativeNoteRule
{
public:
  void describe(RuleEnvironment&);
  std::vector<RelativeNote> getRelativeNotes(RuleEnvironment&);
  int getLength(RuleEnvironment&);
};