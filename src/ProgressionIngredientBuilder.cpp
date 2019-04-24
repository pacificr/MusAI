#include "../include/ProgressionIngredientBuilder.h"

#include "../include/ProgressionIngredient.h"
#include "../include/TriadChordPoolBuilder.h"

ProgressionIngredientBuilder& ProgressionIngredientBuilder::addChordPool(std::shared_ptr<IBuilder<ChordPool>> chordProvider)
{
  mChordPool.add(chordProvider);
  return *this;
}

std::shared_ptr<IIngredient> ProgressionIngredientBuilder::build()
{
  auto progressionIngredient = std::make_shared<ProgressionIngredient>();
  if (mChordPool.size() < 1)
    mChordPool.add(std::make_shared<TriadChordPoolBuilder>());

  for (int i = 0; i < mNumBeats / mChordLength + (0 != mNumBeats % mChordLength); ++i)
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
