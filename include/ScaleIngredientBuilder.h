#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

class ScaleIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    std::string mScaleTitle;
    std::shared_ptr<IIngredient> build();
};
