#pragma once

#include "IIngredient.h"

class ChannelIngredient : public IIngredient
{
  private:
    int mChannel;
  public:
    ChannelIngredient(int channel) : mChannel(channel){};
    void apply(Timeline&, std::string);
};
