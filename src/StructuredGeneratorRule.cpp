#include "../include/StructuredGeneratorRule.h"

#include "../include/StructuredGenerator.h"
#include "../include/IAbsoluteNoteRule.h"

void StructuredGeneratorRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Generator", this);
}

IGenerator* StructuredGeneratorRule::getGenerator(RuleEnvironment* ruleEnvironment)
{
  IAbsoluteNoteRule* noteRule = (IAbsoluteNoteRule*)ruleEnvironment->getRule("TestA");

  StructureControl* control = new StructureControl(noteRule);
  control->addControl(control, *ruleEnvironment);

  StructuredGenerator* generator = new StructuredGenerator(ruleEnvironment, control);
  return generator;
}