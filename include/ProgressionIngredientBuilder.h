#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

class ProgressionIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    std::shared_ptr<IIngredient> build();
};
