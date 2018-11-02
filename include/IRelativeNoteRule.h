#pragma once

#include "IRule.h"
#include "RelativeNote.h"

#include <vector>

class IRelativeNoteRule : public IRule
{
public:
  virtual ~IRelativeNoteRule() = default;
  virtual std::vector<RelativeNote> getRelativeNotes() = 0;
};