#include "../include/TempoIngredient.h"

void TempoIngredient::apply(Timeline& timeline, std::string track)
{
  timeline.add(std::make_shared<Tempo>(mTempo), track);
}
