#pragma once

#include "Timeline.h"

class IIngredient
{
  public:
    virtual ~IIngredient() = default;
    virtual void apply(Timeline&, std::string) = 0;
};
