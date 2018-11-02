#pragma once

#include "IRule.h"
#include "AbsoluteNote.h"

#include <vector>

class IAbsoluteNoteRule : public IRule
{
public:
  virtual ~IAbsoluteNoteRule() = default;
  virtual std::vector<AbsoluteNote> getAbsoluteNotes(RuleEnvironment&) = 0;
};