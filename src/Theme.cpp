#include "../include/Theme.h"

#include "../include/IGenerator.h"

void Theme::addRule(IRule& rule)
{
  rule.describe(mRuleEnvironment);
}

IGenerator* Theme::getGenerator()
{
  srand(time(NULL));
  return (mRuleEnvironment.getRule<IGenerator>("Generator"));
}