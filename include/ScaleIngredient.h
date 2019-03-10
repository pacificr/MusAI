#pragma once

#include "IIngredient.h"

class ScaleIngredient : public IIngredient
{
  private:
    std::shared_ptr<Scale> mScale;
  public:
    ScaleIngredient(std::shared_ptr<Scale>);
    void apply(Timeline&, std::string);
};
