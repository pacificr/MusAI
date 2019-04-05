#include "../include/ChannelIngredientBuilder.h"

#include "../include/ChannelIngredient.h"

std::shared_ptr<IIngredient> ChannelIngredientBuilder::build()
{
  return std::make_shared<ChannelIngredient>(mChannel);
}

void ChannelIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "ChannelIngredientBuilder", "Channel", {
    Describer::intRequirement("channel", "Channel", 0)
  });
}
