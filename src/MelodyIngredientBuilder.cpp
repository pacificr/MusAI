#include "../include/MelodySequenceIngredientBuilder.h"

#include "../include/SequenceIngredient.h"
#include "../include/ChordPitch.h"

std::shared_ptr<IIngredient> MelodySequenceIngredientBuilder::build()
{
  int pitch = mStartingPitch;
  std::shared_ptr<PitchSequence> pc = std::make_shared<PitchSequence>();
  std::shared_ptr<Rhythm> rhythm = std::make_shared<Rhythm>(16);
  for (unsigned int i = 0; i < mNumNotes; ++i)
  {
    pc->add(std::make_shared<Unison>(std::make_shared<ChordPitch>(pitch)));
    pitch += rand() % 3 - 1;

    rhythm->add(RhythmicNote(1, 1, i));
  }

  return std::make_shared<SequenceIngredient>(pc, rhythm);
}

void MelodySequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "MelodySequenceIngredientBuilder", "Melody Sequence");
}
