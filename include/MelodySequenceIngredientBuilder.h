#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class MelodySequenceIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    unsigned int mNumBeats = 16;
    std::string mPitchStyle = "Random";
    std::string mRhythmStyle = "Quarter Notes";
    int mOctave = 0;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
