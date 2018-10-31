#include "../include/StructureControl.h"

StructureControl::StructureControl(INoteProducer* structure)
{
  mNoteProducer = structure;
  mControlID = "temp";//Generate random ID
}

void StructureControl::addControl(StructureControl* structureControl, RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule(mControlID, structureControl);
}

INoteProducer& StructureControl::getNoteProducer() const
{
  return *mNoteProducer;
}

StructureControl& StructureControl::getNext(RuleEnvironment& ruleEnvironment) const
{
  return (StructureControl&)ruleEnvironment.getRule(mControlID);
}