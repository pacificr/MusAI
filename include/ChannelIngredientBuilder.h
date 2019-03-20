#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class ChannelIngredientBuilder : public IBuilder<IIngredient>
{
  public:
    int mChannel;
    std::shared_ptr<IIngredient> build();
    static void registerWith(Describer&);
};
