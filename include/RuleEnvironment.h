#pragma once

#include <string>
#include <map>
#include <memory>

class IRule;

class RuleEnvironment
{
private:
  std::multimap<std::string, std::shared_ptr<IRule>> mRules;
public:
  void add(std::string, const IRule&);
  IRule& get(std::string);
};