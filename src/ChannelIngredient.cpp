#include "../include/ChannelIngredient.h"

void ChannelIngredient::apply(Timeline& timeline, std::string track)
{
  timeline.add(std::make_shared<int>(mChannel), track);
}
