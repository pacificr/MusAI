#include "../include/RuleEnvironment.h"

#include "../include/IRule.h"

#include <string>

void RuleEnvironment::add(std::string fulfills, const IRule& rule)
{
  mRules.insert(std::pair<std::string, std::shared_ptr<IRule>>(fulfills, std::make_shared<IRule>(rule)));
}

IRule& RuleEnvironment::get(std::string requires)
{
  if (mRules.count(requires) > 0)
  {
    unsigned int choice = rand() % mRules.count(requires);
    
    auto rules = mRules.find(requires);

    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }

    return *rules->second;
  }

  //Get default instead
  return *mRules.find(requires)->second;
}