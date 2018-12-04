#include "../include/StructureControl.h"

StructureControl::StructureControl(IAbsoluteNoteRule* structure, std::string id)
{
  mNoteRule = structure;
  mControlID = id;
}

void StructureControl::addControl(StructureControl* structureControl, RuleEnvironment& ruleEnvironment)
{
  std::cout << "ADDED: " << mControlID << " -> " << structureControl->mControlID << std::endl;
  ruleEnvironment.addFulfillment(mControlID, structureControl);
}

IAbsoluteNoteRule& StructureControl::getNoteRule() const
{
  std::cout << "USING: " << mControlID << std::endl;
  return *mNoteRule;
}

StructureControl& StructureControl::getNext(RuleEnvironment& ruleEnvironment) const
{
  return *ruleEnvironment.getRule<StructureControl>(mControlID);
}