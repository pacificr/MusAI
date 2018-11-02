#pragma once

#include "INoteRule.h"

#include <memory>
#include <vector>

class StructureControl : public IRule
{
private:
  std::string mControlID;
  INoteRule* mNoteRule;
public:
  StructureControl(INoteRule*);

  virtual void describe(RuleEnvironment&){};

  void addControl(StructureControl*, RuleEnvironment&);

  INoteRule& getNoteRule() const;
  StructureControl& getNext(RuleEnvironment&) const;
};