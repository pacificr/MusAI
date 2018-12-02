#pragma once

#include "IBuilder.h"

class StepMelodyBuilder : public IBuilder
{
public:
  void describe(RuleEnvironment&);
  IRule *build(RuleEnvironment&);
};