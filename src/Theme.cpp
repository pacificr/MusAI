#include "../include/Theme.h"

#include "../include/IGeneratorRule.h"

void Theme::addRule(IRule& rule)
{
  rule.describe(mRuleEnvironment);
}

IGenerator* Theme::getGenerator()
{
  return (mRuleEnvironment.getRule<IGeneratorRule>("Generator"))->getGenerator(&mRuleEnvironment);
}