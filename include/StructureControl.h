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
  StructureControl(const RuleEnvironment&, INoteProducer&);

  void addControl(StructureControl&);

  INoteProducer& getNoteProducer() const;
  StructureControl& getNext() const;
};