#include "../include/ProgressionIngredientBuilder.h"

#include "../include/ProgressionIngredient.h"
#include "../include/RandomTriadChordPoolBuilder.h"

ProgressionIngredientBuilder& ProgressionIngredientBuilder::addChordPool(std::shared_ptr<IBuilder<ChordPool>> chordProvider)
{
  mChordPool.add(chordProvider);
  return *this;
}

std::shared_ptr<IIngredient> ProgressionIngredientBuilder::build()
{
  auto progressionIngredient = std::make_shared<ProgressionIngredient>();
  if (mChordPool.size() < 1)
    mChordPool.add(std::make_shared<RandomTriadChordPoolBuilder>());

  for (int i = 0; i < 4; ++i)
  {
    if (mInOrder)
      progressionIngredient->pushChord(mChordPool.get()->getChord(i), mChordLength);
    else
      progressionIngredient->pushChord(mChordPool.get()->getChord(), mChordLength);
  }

  return progressionIngredient;
}

void ProgressionIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "ProgressionIngredientBuilder", "Progression", {
    Describer::intRequirement("chordLength", "Chord Length", 4),
    Describer::choiceRequirement("order", "Order", {"Random", "In Order"}),
    Describer::builderRequirement("ChordPoolBuilder", "chordPool", "Chord Pool")
  });
}
