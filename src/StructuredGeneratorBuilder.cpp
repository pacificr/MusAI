#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/StructureControl.h"
#include "../include/TimelineNoteCollectionBuilder.h"

#include "../include/Logger.h"
#define LOC "structure"

StructuredGeneratorBuilder::StructuredGeneratorBuilder()
{
  mNoteCollection.add(std::make_shared<TimelineNoteCollectionBuilder>());
}

std::shared_ptr<IGenerator> StructuredGeneratorBuilder::build()
{
  Logger& logger = Logger::instance();

  if (mMinSections < 1)
    mMinSections = 1;

  mMaxSections = 1;//TEMPORARY
  int numSections = (rand() % (mMaxSections - mMinSections + 1)) + mMinSections;
  int sectionsToBuild = numSections - 1;
  int current = 0;

  logger.log(LOC, "numSections: " + std::to_string(numSections));

  std::vector<std::shared_ptr<StructureControl>> sections;
  sections.resize(numSections);

  std::string id = std::to_string(rand());
  
  sections[current] = std::make_shared<StructureControl>(mNoteCollection.get(), id);
  /*sections[current] = new StructureControl(
    new BasicAbsoluteNoteRule(id),
    id
  );
  ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);*/

  if (sectionsToBuild <= 0)
    sections[current]->addControl(sections[current]);
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
        sections[current] = std::make_shared<StructureControl>(mNoteCollection.get(), id);
        /*sections[selection] = new StructureControl(
          new BasicAbsoluteNoteRule(id),
          id
        );
        ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);*/
        --sectionsToBuild;
      }
      sections[current]->addControl(sections[selection]);
      current = selection;
    }
  }

  return std::make_shared<StructuredGenerator>(sections);
}
