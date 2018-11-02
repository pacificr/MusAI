#include "../include/StructuredGeneratorRule.h"

#include "../include/StructuredGenerator.h"

void StructuredGeneratorRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Generator", this);
}

IGenerator* StructuredGeneratorRule::getGenerator(RuleEnvironment* ruleEnvironment)
{
  INoteRule* noteRule = (INoteRule*)&ruleEnvironment->getRule("Test");

  StructureControl* control = new StructureControl(noteRule);
  control->addControl(control, *ruleEnvironment);

  StructuredGenerator* generator = new StructuredGenerator(ruleEnvironment, control);
  return generator;
}