#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class ArpeggioSequenceIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    int mLength;
    int mNumNotes;
    int mNumBeats;
    int mOctave;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
