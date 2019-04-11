#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class HarmonySequenceIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    unsigned int mNumBeats;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
