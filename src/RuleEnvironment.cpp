#include "../include/RuleEnvironment.h"

void RuleEnvironment::add(std::string fulfills, std::shared_ptr<IRule> rule)
{
  mRules.insert(std::pair<std::string, std::shared_ptr<IRule>>(fulfills, rule));
}

std::shared_ptr<IRule> RuleEnvironment::get(std::string requires)
{
  if (mRules.count(requires) > 0)
  {
    unsigned int choice = rand() % mRules.count(requires);
    
    auto rules = mRules.find(requires);

    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }

    return rules->second;
  }

  return NULL;
}