#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/StructureControl.h"
#include "../include/TimelineNoteCollectionBuilder.h"

#include "../include/Logger.h"
#define LOC "structure"

StructuredGeneratorBuilder::StructuredGeneratorBuilder(unsigned int minSections, unsigned int maxSections)
  : mMinSections(minSections), mMaxSections(maxSections){};

StructuredGeneratorBuilder& StructuredGeneratorBuilder::addNoteCollectionBuilder(std::shared_ptr<IBuilder<INoteCollection>> builder)
{
  mNoteCollection.add(builder);
  return *this;
}

std::shared_ptr<IGenerator> StructuredGeneratorBuilder::build()
{
  Logger& logger = Logger::instance();

  if (mMinSections < 1)
    mMinSections = 1;

  int numSections = (rand() % (mMaxSections - mMinSections + 1)) + mMinSections;
  int sectionsToBuild = numSections - 1;
  int current = 0;

  logger.log(LOC, "numSections: " + std::to_string(numSections));

  std::vector<std::shared_ptr<StructureControl>> sections;
  sections.resize(numSections);
  
  sections[current] = std::make_shared<StructureControl>(mNoteCollection.get());

  if (sectionsToBuild <= 0)
    sections[current]->addControl(sections[current]);
  else
  {
    for (int i = 1; i < numSections; ++i)
      sections[i] = nullptr;

    while(sectionsToBuild > 0 || current != 0)
    {
      int selection = rand() % numSections;
      if(sections[selection] == nullptr)
      {
        mNoteCollection.randomize();
        sections[selection] = std::make_shared<StructureControl>(mNoteCollection.get());
        --sectionsToBuild;
      }
      sections[current]->addControl(sections[selection]);
      current = selection;
    }
  }

  return std::make_shared<StructuredGenerator>(sections);
}
