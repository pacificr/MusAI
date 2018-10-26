#pragma once

#include "IRule.h"

#include <map>
#include <memory>

class RuleEnvironment
{
private:
  std::multimap<std::string, std::shared_ptr<IRule>> mRules;
public:
  void add(std::string, std::shared_ptr<IRule>);
  std::shared_ptr<IRule> get(std::string);
};