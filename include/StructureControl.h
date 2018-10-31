#pragma once

#include "INoteProducer.h"

#include <memory>
#include <vector>

class StructureControl : public IRule
{
private:
  std::string mControlID;
  INoteProducer* mNoteProducer;
public:
  StructureControl(INoteProducer*);

  virtual void describe(RuleEnvironment&){};

  void addControl(StructureControl*, RuleEnvironment&);

  INoteProducer& getNoteProducer() const;
  StructureControl& getNext(RuleEnvironment&) const;
};