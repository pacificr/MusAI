#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class CustomScaleIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    std::vector<int> mDegrees;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
