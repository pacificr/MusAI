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

IRule *RuleEnvironment::getBuilt(IBuilder *builder)
{
  return builder->build(*this);
}