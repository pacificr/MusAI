#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

class MelodySequenceIngredientBuilder : public IBuilder<IIngredient>
{
  private:
    int mStartingPitch = 0;
    unsigned int mNumNotes = 16;
  public:
    std::shared_ptr<IIngredient> build();
};
