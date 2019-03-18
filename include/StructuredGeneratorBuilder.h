#pragma once

#include "IBuilder.h"
#include "IGenerator.h"

#include "Describer.h"
#include "BuilderSet.h"
#include "INoteCollection.h"

class StructuredGeneratorBuilder : public IBuilder<IGenerator>
{
private:
  BuilderSet<INoteCollection> mNoteCollection;
public:
  int mMinSections;
  int mMaxSections;
  StructuredGeneratorBuilder& addNoteCollectionBuilder(std::shared_ptr<IBuilder<INoteCollection>>);
  std::shared_ptr<IGenerator> build();
  static void registerWith(Describer&);
};
