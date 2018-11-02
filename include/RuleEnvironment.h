#pragma once

#include <string>
#include <map>
#include <memory>

class IRule;

class RuleEnvironment
{
private:
  std::multimap<std::string, IRule*> mRules;
public:
  void addRule(std::string, IRule*);
  IRule* getRule(std::string);
};