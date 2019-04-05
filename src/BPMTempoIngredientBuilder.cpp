#include "../include/BPMTempoIngredientBuilder.h"

#include "../include/TempoIngredient.h"

std::shared_ptr<IIngredient> BPMTempoIngredientBuilder::build()
{
  if (mMaxBPM < mMinBPM)
    mMaxBPM = mMinBPM;
  return std::make_shared<TempoIngredient>(rand() % (mMaxBPM - mMinBPM + 1) + mMinBPM);
}

void BPMTempoIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "BPMTempoIngredientBuilder", "BPM", {
    Describer::intRequirement("minBPM", "Min BPM", 60),
    Describer::intRequirement("maxBPM", "Max BPM", 120),
  });
}
