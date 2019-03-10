#include "../include/ScaleIngredient.h"

ScaleIngredient::ScaleIngredient(std::shared_ptr<Scale> scale)
  :mScale(scale){}

void ScaleIngredient::apply(Timeline& timeline, std::string track)
{
  timeline.add(mScale, track);
}
