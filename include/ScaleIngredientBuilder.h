#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class ScaleIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    std::string mScaleTitle = "major";
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
