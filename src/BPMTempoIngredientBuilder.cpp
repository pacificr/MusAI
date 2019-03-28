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
  describer.registerBuilder("IngredientBuilder", "BPMTempoIngredientBuilder", "BPM");
  describer.registerIntRequirement("IngredientBuilder", "BPMTempoIngredientBuilder", "minBPM", "Min BPM", 60);
  describer.registerIntRequirement("IngredientBuilder", "BPMTempoIngredientBuilder", "maxBPM", "Max BPM", 120);
}
