#pragma once

#include "IRule.h"
#include "IGenerator.h"

class IGeneratorProducer : public IRule
{
public:
  virtual IGenerator* getGenerator(RuleEnvironment*) = 0;
};