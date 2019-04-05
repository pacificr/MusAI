#include "../include/CustomScaleIngredientBuilder.h"

#include "../include/ScaleIngredient.h"

std::shared_ptr<IIngredient> CustomScaleIngredientBuilder::build()
{
  return std::make_shared<ScaleIngredient>(std::make_shared<Scale>(mDegrees));
}

void CustomScaleIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "CustomScaleIngredientBuilder", "Custom Scale", {
    Describer::arrayRequirement("degrees", "Degrees",Describer::intRequirement(Describer::SUB_ATTRIBUTE, "Degree", 0))
  });
}
