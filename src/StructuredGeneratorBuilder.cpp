#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/BasicAbsoluteNoteRule.h"
#include "../include/StructureControl.h"
#include "../include/TimelineAbsoluteNoteRule.h"
//#include "../include/IBuilder.h"

#include "../include/Logger.h"
#define LOC "structure"

void StructuredGeneratorBuilder::describe(RuleEnvironment &ruleEnvironment)
{
  ruleEnvironment.addBuilds("Generator", this);
}

IRule *StructuredGeneratorBuilder::build(RuleEnvironment &ruleEnvironment)
{
  Logger& logger = Logger::instance();

  if (mMinSections < 1)
    mMinSections = 1;

  mMaxSections = 1;//TEMPORARY
  int numSections = (rand() % (mMaxSections - mMinSections + 1)) + mMinSections;
  int sectionsToBuild = numSections - 1;
  int current = 0;
  //IBuilder *melodyBuilder = ruleEnvironment.getBuilder("Melody");

  logger.log(LOC, "numSections: " + std::to_string(numSections));

  std::vector<StructureControl*> sections;
  sections.resize(numSections);

  std::string id = std::to_string(rand());

  sections[current] = new StructureControl(new TimelineAbsoluteNoteRule(new Timeline()), id);
  /*sections[current] = new StructureControl(
    new BasicAbsoluteNoteRule(id),
    id
  );
  ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);*/

  if (sectionsToBuild <= 0)
    sections[current]->addControl(sections[current], ruleEnvironment);
  else
  {
    for (int i = 1; i < numSections; ++i)
      sections[i] = NULL;

    while(sectionsToBuild > 0 || current != 0)
    {
      int selection = rand() % numSections;
      if(sections[selection] == NULL)
      {
        id = std::to_string(rand());
        sections[current] = new StructureControl(new TimelineAbsoluteNoteRule(new Timeline()), id);
        /*sections[selection] = new StructureControl(
          new BasicAbsoluteNoteRule(id),
          id
        );
        ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);*/
        --sectionsToBuild;
      }
      sections[current]->addControl(sections[selection], ruleEnvironment);
      current = selection;
    }
  }

  return new StructuredGenerator(&ruleEnvironment, sections[0]);
}
