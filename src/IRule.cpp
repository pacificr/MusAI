#include "../include/IRule.h"

IRule::IRule(const RuleEnvironment& ruleEnvironment)
{
  mRuleEnvironment = std::make_shared<RuleEnvironment>(ruleEnvironment);
}

//IRule::~IRule(){}