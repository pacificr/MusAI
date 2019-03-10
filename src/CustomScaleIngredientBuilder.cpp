#include "../include/CustomScaleIngredientBuilder.h"

#include "../include/ScaleIngredient.h"

std::shared_ptr<IIngredient> CustomScaleIngredientBuilder::build()
{
  return std::make_shared<ScaleIngredient>(std::make_shared<Scale>(mDegrees));
}
