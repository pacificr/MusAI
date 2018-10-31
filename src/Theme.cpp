#include "../include/Theme.h"

#include "../include/IGeneratorProducer.h"

void Theme::addRule(IRule& rule)
{
  rule.describe(mRuleEnvironment);
}

IGenerator* Theme::getGenerator()
{
  return ((IGeneratorProducer&)mRuleEnvironment.getRule("Generator")).getGenerator(&mRuleEnvironment);
}