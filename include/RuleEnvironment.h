#pragma once

#include <string>
#include <map>
#include <memory>

class IRule;
class IBuilder;

class RuleEnvironment
{
private:
  std::multimap<std::string, IRule*> mRules;
  std::multimap<std::string, IBuilder*> mBuilds;
  IRule *getBuilt(IBuilder&);
public:
  void addFulfillment(std::string, IRule*);
  void addBuilds(std::string, IBuilder*);
  IBuilder *getBuilder(std::string);
  template <class T> T* getRule(std::string);
};

#include "../src/RuleEnvironment.tcc"