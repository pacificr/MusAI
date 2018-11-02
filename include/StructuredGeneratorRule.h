#pragma once

#include "IGeneratorRule.h"

class StructuredGeneratorRule : public IGeneratorRule
{
public:
  virtual void describe(RuleEnvironment&);
  virtual IGenerator* getGenerator(RuleEnvironment*);
};