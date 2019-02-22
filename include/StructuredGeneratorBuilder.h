#pragma once

#include "IBuilder.h"
#include "IGenerator.h"

#include "BuilderSet.h"
#include "INoteCollection.h"

class StructuredGeneratorBuilder : public IBuilder<IGenerator>
{
private:
  BuilderSet<INoteCollection> mNoteCollection;
  unsigned int mMinSections = 1;
  unsigned int mMaxSections = 4;
public:
  StructuredGeneratorBuilder();
  std::shared_ptr<IGenerator> build();
};
