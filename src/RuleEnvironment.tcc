#include "../include/RuleEnvironment.h"

#include <iostream>

template <class T> T* RuleEnvironment::getRule(std::string requires)
{
  if (mRules.count(requires) > 0)
  {
    unsigned int choice = rand() % mRules.count(requires);
    auto rules = mRules.find(requires);
    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }
    return (T*)rules->second;
  }

  if (mBuilds.count(requires) > 0)
  {
    unsigned int choice = rand() % mBuilds.count(requires);
    auto rules = mBuilds.find(requires);
    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }
    return (T*)getBuilt(rules->second);
  }

  std::cout << "NO FULFILLMENT OR BUILD RULE FOUND FOR: " << requires << std::endl;

  return NULL;
}