#pragma once

#include "IBuilder.h"
#include "INoteCollection.h"

#include "IIngredient.h"
#include "BuilderSet.h"

class TimelineNoteCollectionBuilder : public IBuilder<INoteCollection>
{
  private:
    BuilderSet<IIngredient> mMelody;
    BuilderSet<IIngredient> mProgression;
    BuilderSet<IIngredient> mHarmony;
  public:
    TimelineNoteCollectionBuilder();
    std::shared_ptr<INoteCollection> build();
};
