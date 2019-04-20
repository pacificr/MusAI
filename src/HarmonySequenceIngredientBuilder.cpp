#include "../include/HarmonySequenceIngredientBuilder.h"

#include "../include/ChordPitch.h"
#include "../include/SequenceIngredient.h"

std::shared_ptr<IIngredient> HarmonySequenceIngredientBuilder::build()
{
  std::shared_ptr<PitchSequence> pc = std::make_shared<PitchSequence>();
  std::shared_ptr<Rhythm> r = std::make_shared<Rhythm>(mNumBeats);

  int i = 0;
  while (i * mChordLength < mNumBeats)
  {
    auto unison = std::make_shared<Unison>();
    for (unsigned int j = 0; j < mNotesPerChord; ++j)
      unison->add(std::make_shared<ChordPitch>(j, mOctave));

    pc->add(unison);
    r->add(RhythmicNote(std::min(mChordLength, mNumBeats - (mChordLength * i)), 1, i));

    ++i;
  }

  return std::make_shared<SequenceIngredient>(pc, r);
}

void HarmonySequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "HarmonySequenceIngredientBuilder", "Harmony", {
    Describer::intRequirement("chordLength", "Chord Length", 4),
    Describer::intRequirement("notesPerChord", "Notes Per Chord", 3),
    Describer::intRequirement("octave", "Octave", -1)
  });
}
