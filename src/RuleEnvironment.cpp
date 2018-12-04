#include "../include/RuleEnvironment.h"

#include "../include/IBuilder.h"

#include <string>

void RuleEnvironment::addFulfillment(std::string fulfills, IRule* rule)
{
  mRules.insert(std::pair<std::string, IRule*>(fulfills, rule));
}

void RuleEnvironment::addBuilds(std::string builds, IBuilder* builder)
{
  mBuilds.insert(std::pair<std::string, IBuilder*>(builds, builder));
}

IRule *RuleEnvironment::getBuilt(IBuilder &builder)
{
  return builder.build(*this);
}

IBuilder *RuleEnvironment::getBuilder(std::string requires)
{
  if (mBuilds.count(requires) > 0)
  {
    //std::cout << "BUILDING: " << requires << std::endl;
    unsigned int choice = rand() % mBuilds.count(requires);
    auto rules = mBuilds.find(requires);
    for (unsigned int i = 0; i < choice; ++i)
    {
      ++rules;
    }
    return (IBuilder*)rules->second;
  }

  std::cout << "NO FULFILLMENT OR BUILD RULE FOUND FOR: " << requires << ". CRASHING!" << std::endl;

  return NULL;
}