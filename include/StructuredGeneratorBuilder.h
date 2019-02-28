#pragma once

#include "IBuilder.h"
#include "IGenerator.h"

#include "BuilderSet.h"
#include "INoteCollection.h"

class StructuredGeneratorBuilder : public IBuilder<IGenerator>
{
private:
  BuilderSet<INoteCollection> mNoteCollection;
public:
  int mMinSections;
  int mMaxSections;
  StructuredGeneratorBuilder(unsigned int minSections = 1, unsigned int maxSections = 4);
  StructuredGeneratorBuilder& addNoteCollectionBuilder(std::shared_ptr<IBuilder<INoteCollection>>);
  std::shared_ptr<IGenerator> build();
};
