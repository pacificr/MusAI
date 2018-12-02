#include "../include/StructureControl.h"

StructureControl::StructureControl(IAbsoluteNoteRule* structure)
{
  mNoteRule = structure;
  mControlID = "temp";//Generate random ID
}

void StructureControl::addControl(StructureControl* structureControl, RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addFulfillment(mControlID, structureControl);
}

IAbsoluteNoteRule& StructureControl::getNoteRule() const
{
  return *mNoteRule;
}

StructureControl& StructureControl::getNext(RuleEnvironment& ruleEnvironment) const
{
  return *ruleEnvironment.getRule<StructureControl>(mControlID);
}