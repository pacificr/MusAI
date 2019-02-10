#include "../include/StructureControl.h"

#include "../include/Logger.h"

#define LOC "structure"

StructureControl::StructureControl(IAbsoluteNoteRule* structure, std::string id)
{
  mNoteRule = structure;
  mControlID = id;
}

void StructureControl::addControl(StructureControl* structureControl, RuleEnvironment& ruleEnvironment)
{
  Logger::instance().log(LOC, "ADDED: " + mControlID + " -> " + structureControl->mControlID);
  ruleEnvironment.addFulfillment(mControlID, structureControl);
}

IAbsoluteNoteRule& StructureControl::getNoteRule() const
{
  Logger::instance().log(LOC, "USING: " + mControlID);
  return *mNoteRule;
}

StructureControl& StructureControl::getNext(RuleEnvironment& ruleEnvironment) const
{
  return *ruleEnvironment.getRule<StructureControl>(mControlID);
}
