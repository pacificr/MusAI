#pragma once

#include "IRule.h"
#include "RelativeNote.h"

#include <vector>

class IRelativeNoteRule : public IRule
{
public:
  virtual ~IRelativeNoteRule() = default;
  virtual std::vector<RelativeNote> getRelativeNotes(RuleEnvironment&) = 0;
  virtual int getLength() = 0;
};