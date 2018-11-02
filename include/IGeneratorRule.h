#pragma once

#include "IRule.h"
#include "IGenerator.h"

class IGeneratorRule : public IRule
{
public:
  virtual IGenerator* getGenerator(RuleEnvironment*) = 0;
};