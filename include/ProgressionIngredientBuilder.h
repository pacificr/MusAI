#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class ProgressionIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
