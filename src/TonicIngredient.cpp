#include "../include/TonicIngredient.h"

void TonicIngredient::apply(Timeline& timeline, std::string track)
{
  timeline.add(std::make_shared<Tonic>(mTonic, mOctave));
}
