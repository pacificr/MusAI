#pragma once

#include "IGeneratorProducer.h"

class StructuredGeneratorProducer : public IGeneratorProducer
{
public:
  virtual void describe(RuleEnvironment&);
  virtual IGenerator* getGenerator(RuleEnvironment*);
};