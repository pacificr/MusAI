#pragma once

#include "IRelativeNoteRule.h"

class TestRule : public IRelativeNoteRule
{
private:
  int mLength = 0;
public:
  void describe(RuleEnvironment&);
  std::vector<RelativeNote> getRelativeNotes(RuleEnvironment&);
  int getLength();
};