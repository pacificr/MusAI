#pragma once

#include "IBuilder.h"
#include "IGenerator.h"

#include "Describer.h"
#include "BuilderSet.h"
#include "INoteCollection.h"

class StructuredGeneratorBuilder : public IBuilder<IGenerator>
{
private:
  std::vector<std::shared_ptr<BuilderSet<INoteCollection>>> mFixedNoteCollections;
  BuilderSet<INoteCollection> mNoteCollection;
public:
  int mMinSections;
  int mMaxSections;
  StructuredGeneratorBuilder& addFixedNoteCollectionBuilder(std::shared_ptr<BuilderSet<INoteCollection>>);
  StructuredGeneratorBuilder& addNoteCollectionBuilder(std::shared_ptr<IBuilder<INoteCollection>>);
  std::shared_ptr<IGenerator> build();
  static void registerWith(Describer&);
};
