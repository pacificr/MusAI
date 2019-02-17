#pragma once

#include "IAbsoluteNoteRule.h"

#include <memory>
#include <vector>

class StructureControl : public IRule
{
private:
  std::shared_ptr<IAbsoluteNoteRule> mNoteRule;
  std::string mControlID;
public:
  StructureControl(std::shared_ptr<IAbsoluteNoteRule>, std::string);

  virtual void describe(RuleEnvironment&){};

  void addControl(StructureControl*, RuleEnvironment&);

  IAbsoluteNoteRule& getNoteRule() const;
  StructureControl& getNext(RuleEnvironment&) const;
};
