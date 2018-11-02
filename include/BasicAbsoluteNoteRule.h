#pragma once

#include "IAbsoluteNoteRule.h"

class BasicAbsoluteNoteRule : public IAbsoluteNoteRule
{
public:
  void describe(RuleEnvironment&);
  std::vector<AbsoluteNote> getAbsoluteNotes(RuleEnvironment&);
};