#include "../include/StructuredGeneratorProducer.h"

#include "../include/StructuredGenerator.h"

void StructuredGeneratorProducer::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Generator", this);
}

IGenerator* StructuredGeneratorProducer::getGenerator(RuleEnvironment* ruleEnvironment)
{
  INoteProducer* noteProducer = (INoteProducer*)&ruleEnvironment->getRule("Test");

  StructureControl* control = new StructureControl(noteProducer);
  control->addControl(control, *ruleEnvironment);

  StructuredGenerator* generator = new StructuredGenerator(ruleEnvironment, control);
  return generator;
}