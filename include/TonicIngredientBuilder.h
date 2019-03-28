#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class TonicIngredientBuilder : public IBuilder<IIngredient>
{
public:
  std::string mTonicTitle = "random";
  int mOctave = 5;
  std::shared_ptr<IIngredient> build();
  static void registerWith(Describer&);
};
