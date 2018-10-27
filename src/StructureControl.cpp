#include "../include/StructureControl.h"

StructureControl::StructureControl(const RuleEnvironment& ruleEnironment, INoteProducer& structure) : IRule(ruleEnironment)
{
  mNoteProducer = &structure;
  mControlID = "temp";//Generate random ID
}

void StructureControl::addControl(const StructureControl& structureControl)
{
  mRuleEnvironment->add(mControlID, structureControl);
}

INoteProducer& StructureControl::getNoteProducer() const
{
  return *mNoteProducer;
}

StructureControl& StructureControl::getNext() const
{
  return (StructureControl&)mRuleEnvironment->get(mControlID);
}