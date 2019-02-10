#pragma once

#include "IBuilder.h"

class StructuredGeneratorBuilder : public IBuilder
{
private:
  unsigned int mMinSections = 1;
  unsigned int mMaxSections = 4;
public:
  void describe(RuleEnvironment&);
  IRule *build(RuleEnvironment&);
};
