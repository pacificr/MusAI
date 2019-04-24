#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "BuilderSet.h"
#include "ChordPool.h"
#include "Describer.h"

class ProgressionIngredientBuilder : public IBuilder<IIngredient>
{
  private:
    BuilderSet<ChordPool> mChordPool;
  public:
    int mChordLength = 4;
    int mNumBeats = 64;
    bool mInOrder = false;
    ProgressionIngredientBuilder& addChordPool(std::shared_ptr<IBuilder<ChordPool>>);
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
