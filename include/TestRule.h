#pragma once

#include "INoteRule.h"

class TestRule : public INoteRule
{
public:
  virtual void describe(RuleEnvironment&);
  virtual std::vector<Note> getNotes();
};