#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/BasicAbsoluteNoteRule.h"
#include "../include/StructureControl.h"
#include "../include/IBuilder.h"

void StructuredGeneratorBuilder::describe(RuleEnvironment &ruleEnvironment)
{
  ruleEnvironment.addBuilds("Generator", this);
}

IRule *StructuredGeneratorBuilder::build(RuleEnvironment &ruleEnvironment)
{
  if (minSections < 1)
    minSections = 1;

  int numSections = (rand() % (maxSections - minSections)) + minSections;
  int sectionsToBuild = numSections - 1;
  int current = 0;
  IBuilder *melodyBuilder = ruleEnvironment.getBuilder("Melody");

  std::vector<StructureControl*> sections;
  sections.resize(numSections);

  std::string id = std::to_string(rand());

  sections[current] = new StructureControl(
    new BasicAbsoluteNoteRule(id),
    id
  );
  ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);

  if (sectionsToBuild <= 0)
    sections[current]->addControl(sections[current], ruleEnvironment);
  else
  {
    for (int i = 1; i < numSections; ++i)
      sections[i] = NULL;

    while(sectionsToBuild > 0 || current != 0)
    {
      std::cout << "CURRENT: " << current << std::endl;
      int selection = rand() % numSections;
      if(sections[selection] == NULL)
      {
        id = std::to_string(rand());
        sections[selection] = new StructureControl(
          new BasicAbsoluteNoteRule(id),
          id
        );
        ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);
        --sectionsToBuild;
      }
      sections[current]->addControl(sections[selection], ruleEnvironment);
      current = selection;
    }
  }

  return new StructuredGenerator(&ruleEnvironment, sections[0]);
}