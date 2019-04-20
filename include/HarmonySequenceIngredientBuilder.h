#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class HarmonySequenceIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    unsigned int mNumBeats;
    unsigned int mChordLength;
    unsigned int mNotesPerChord;
    int mOctave;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
