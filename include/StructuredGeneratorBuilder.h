#pragma once

#include "IBuilder.h"

class StructuredGeneratorBuilder : public IBuilder
{
private:
  unsigned int minSections = 1;
  unsigned int maxSections = 4;
public:
  void describe(RuleEnvironment&);
  IRule *build(RuleEnvironment&);
};