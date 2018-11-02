#include "../include/StructureControl.h"

StructureControl::StructureControl(INoteRule* structure)
{
  mNoteRule = structure;
  mControlID = "temp";//Generate random ID
}

void StructureControl::addControl(StructureControl* structureControl, RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule(mControlID, structureControl);
}

INoteRule& StructureControl::getNoteRule() const
{
  return *mNoteRule;
}

StructureControl& StructureControl::getNext(RuleEnvironment& ruleEnvironment) const
{
  return (StructureControl&)ruleEnvironment.getRule(mControlID);
}