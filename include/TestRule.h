#pragma once

#include "INoteProducer.h"

class TestRule : public INoteProducer
{
public:
  TestRule(const RuleEnvironment& re) : INoteProducer(re){};
  virtual std::vector<Note> getNotes();
};