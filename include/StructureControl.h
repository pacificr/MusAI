#pragma once

#include "IAbsoluteNoteRule.h"

#include <memory>
#include <vector>

class StructureControl : public IRule
{
private:
  std::string mControlID;
  IAbsoluteNoteRule* mNoteRule;
public:
  StructureControl(IAbsoluteNoteRule*);

  virtual void describe(RuleEnvironment&){};

  void addControl(StructureControl*, RuleEnvironment&);

  IAbsoluteNoteRule& getNoteRule() const;
  StructureControl& getNext(RuleEnvironment&) const;
};