#pragma once

#include "IRelativeNoteRule.h"

class AbsoluteRelativeNoteRule : public IRelativeNoteRule
{
private:
  std::vector<RelativeNote> mNotes;
  int mLength = 0;
public:
  AbsoluteRelativeNoteRule(std::vector<RelativeNote>, int);
  void describe(RuleEnvironment&);
  std::vector<RelativeNote> getRelativeNotes(RuleEnvironment&);
  int getLength(RuleEnvironment&);
};