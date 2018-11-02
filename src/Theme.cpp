#include "../include/Theme.h"

#include "../include/IGeneratorRule.h"

void Theme::addRule(IRule& rule)
{
  rule.describe(mRuleEnvironment);
}

IGenerator* Theme::getGenerator()
{
  return ((IGeneratorRule&)mRuleEnvironment.getRule("Generator")).getGenerator(&mRuleEnvironment);
}