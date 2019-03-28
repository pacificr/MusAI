#pragma once

#include "IBuilder.h"
#include "IIngredient.h"

#include "Describer.h"

class BPMTempoIngredientBuilder : public IBuilder<IIngredient>
{
public:
  int mMinBPM = 60;
  int mMaxBPM = 120;

  std::shared_ptr<IIngredient> build();
  static void registerWith(Describer&);
};
