#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class ArpeggioSequenceIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    int mNumBeats;
    int mNumNotes;
    int mOverBeats;
    int mOctave;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
