#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/StructureControl.h"
#include "../include/TimelineNoteCollectionBuilder.h"

#include "../include/Logger.h"
#define LOC "structure"

StructuredGeneratorBuilder& StructuredGeneratorBuilder::addFixedNoteCollectionBuilder(std::shared_ptr<BuilderSet<INoteCollection>> builderSet)
{
  mFixedNoteCollections.push_back(builderSet);
  return *this;
}

StructuredGeneratorBuilder& StructuredGeneratorBuilder::addNoteCollectionBuilder(std::shared_ptr<IBuilder<INoteCollection>> builder)
{
  mNoteCollection.add(builder);
  return *this;
}

std::shared_ptr<IGenerator> StructuredGeneratorBuilder::build()
{
  Logger& logger = Logger::instance();

  if (mMinSections < 1 && mFixedNoteCollections.size() < 1)
    mMinSections = 1;
  if (mMinSections > mMaxSections)
    mMaxSections = mMinSections;

  unsigned int numSections = (rand() % (mMaxSections - mMinSections + 1)) + mMinSections + mFixedNoteCollections.size();
  unsigned int sectionsToBuild = numSections - 1;
  unsigned int current = 0;

  logger.log(LOC, "numSections: " + std::to_string(numSections) + " (" + std::to_string(mFixedNoteCollections.size()) + " fixed)");

  std::vector<std::shared_ptr<StructureControl>> sections;
  sections.resize(numSections);
 
  if (mFixedNoteCollections.size() > 0)
    sections[0] = std::make_shared<StructureControl>(mFixedNoteCollections[0]->get());
  else 
    sections[0] = std::make_shared<StructureControl>(mNoteCollection.get());

  if (sectionsToBuild <= 0)
    sections[current]->addControl(sections[current]);
  else
  {
    for (unsigned int i = 1; i < numSections; ++i)
      sections[i] = nullptr;

    while(sectionsToBuild > 0 || current != 0)
    {
      unsigned int selection = rand() % numSections;
      if(sections[selection] == nullptr)
      {
        if (selection < mFixedNoteCollections.size())
          sections[selection] = std::make_shared<StructureControl>(mFixedNoteCollections[current]->get());
        else
        {
          mNoteCollection.randomize();
          sections[selection] = std::make_shared<StructureControl>(mNoteCollection.get());
        }
        --sectionsToBuild;
      }
      sections[current]->addControl(sections[selection]);
      current = selection;
    }
  }

  return std::make_shared<StructuredGenerator>(sections);
}

void StructuredGeneratorBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("GeneratorBuilder", "StructuredGeneratorBuilder", "Structured Generator", {
    Describer::arrayRequirement("fixedSections", "Fixed Sections", 
      Describer::builderRequirement("NoteCollectionBuilder", Describer::SUB_ATTRIBUTE, "Note Collection")),
    Describer::intRequirement("minSections", "Minimum Random Sections", 1),
    Describer::intRequirement("maxSections", "Maximum Random Sections", 3),
    Describer::builderRequirement("NoteCollectionBuilder", "noteCollection", "Random Note Collection")
  });
}
