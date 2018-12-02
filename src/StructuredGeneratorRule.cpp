#include "../include/StructuredGeneratorRule.h"

#include "../include/StructuredGenerator.h"
#include "../include/IAbsoluteNoteRule.h"

void StructuredGeneratorRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addFulfillment("Generator", this);
}

IGenerator* StructuredGeneratorRule::getGenerator(RuleEnvironment* ruleEnvironment)
{
  auto noteRule = ruleEnvironment->getRule<IAbsoluteNoteRule>("TestA");

  StructureControl* control = new StructureControl(noteRule);
  control->addControl(control, *ruleEnvironment);

  StructuredGenerator* generator = new StructuredGenerator(ruleEnvironment, control);
  return generator;
}