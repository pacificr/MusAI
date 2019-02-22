#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

class HarmonySequenceIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    std::shared_ptr<IIngredient> build();
};
