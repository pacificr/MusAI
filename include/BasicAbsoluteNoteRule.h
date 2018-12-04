#pragma once

#include "IAbsoluteNoteRule.h"

class BasicAbsoluteNoteRule : public IAbsoluteNoteRule
{
private:
  std::string mID;
public:
  BasicAbsoluteNoteRule(std::string);
  void describe(RuleEnvironment&);
  std::vector<AbsoluteNote> getAbsoluteNotes(RuleEnvironment&);
  double getLength(RuleEnvironment&);
};