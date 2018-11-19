#pragma once

#include "IRelativeNoteRule.h"

class TestRule : public IRelativeNoteRule
{
public:
  void describe(RuleEnvironment&);
  std::vector<RelativeNote> getRelativeNotes();
  int getLength();
};