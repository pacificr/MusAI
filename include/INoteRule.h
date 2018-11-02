#pragma once

#include "IRule.h"
#include "Note.h"

#include <vector>

class INoteRule : public IRule
{
public:
  virtual ~INoteRule() = default;
  virtual std::vector<Note> getNotes() = 0;
};