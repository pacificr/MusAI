#pragma once

#include "INoteProducer.h"

class TestRule : public INoteProducer
{
public:
  virtual void describe(RuleEnvironment&);
  virtual std::vector<Note> getNotes();
};