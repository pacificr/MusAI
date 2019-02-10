#include "../include/RuleEnvironment.h"

#include <iostream>

template <class T> T* RuleEnvironment::getRule(std::string requires)
{
  //std::cout << "LOOKING FOR: " << requires << std::endl;
  if (mRules.count(requires) > 0)
  {
    //std::cout << "FOUND: " << requires << std::endl;
    unsigned int choice = rand() % mRules.count(requires);
    auto rules = mRules.find(requires);
    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }
    return (T*)rules->second;
  }

  //std::cout << "NOT FOUND, LOOKING FOR BUILDER: " << requires << std::endl;

  if (mBuilds.count(requires) > 0)
  {
    //std::cout << "BUILDING: " << requires << std::endl;
    unsigned int choice = rand() % mBuilds.count(requires);
    auto rules = mBuilds.find(requires);
    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }
    //std::cout << "ADDING FULFILLMENT: " << requires << std::endl;
    IRule *newRule = getBuilt(*rules->second);
    //std::cout << "ADDED FULFILLMENT: " << requires << std::endl;
    addFulfillment(requires, newRule);
    return (T*)newRule;
  }

  std::cout << "NO FULFILLMENT OR BUILD RULE FOUND FOR: " << requires << ". CRASHING!" << std::endl;

  return NULL;
}
