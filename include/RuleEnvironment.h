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
  void add(std::string, IRule&);
  IRule& get(std::string);
};