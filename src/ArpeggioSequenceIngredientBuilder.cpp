#include "../include/ArpeggioSequenceIngredientBuilder.h"

#include "../include/SequenceIngredient.h"
#include "../include/ChordPitch.h"

std::shared_ptr<IIngredient> ArpeggioSequenceIngredientBuilder::build()
{
  int pitch = 0;
  int note = 0;
  std::shared_ptr<PitchSequence> pc = std::make_shared<PitchSequence>();
  std::shared_ptr<Rhythm> r = std::make_shared<Rhythm>(mNumBeats);

  if (mNumNotes <= 0)
    mNumNotes = rand() % 5 + 2;
  if (mOverBeats <= 0)
    mOverBeats = rand() % 2 + 1;

  while ((note * mOverBeats) / mNumNotes < mNumBeats)
  {
    pc->add(std::make_shared<Unison>(std::make_shared<ChordPitch>(pitch++, mOctave)));
    if (pitch >= mNumNotes)
      pitch = 0;

    r->add(RhythmicNote(mOverBeats, mNumNotes, note++));
  }
  return std::make_shared<SequenceIngredient>(pc, r);
}

void ArpeggioSequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "ArpeggioSequenceIngredientBuilder", "Arpeggio", { 
    Describer::intRequirement("numNotes", "Number of Notes (0 for random)", 0),
    Describer::intRequirement("overBeats", "Over Number of Beats (0 for random)", 0),
    Describer::intRequirement("octave", "Octave", 0),
  });
}
