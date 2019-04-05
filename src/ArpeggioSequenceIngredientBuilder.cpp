#include "../include/ArpeggioSequenceIngredientBuilder.h"

#include "../include/SequenceIngredient.h"
#include "../include/ChordPitch.h"

std::shared_ptr<IIngredient> ArpeggioSequenceIngredientBuilder::build()
{
  int pitch = 0;
  int note = 0;
  std::shared_ptr<PitchSequence> pc = std::make_shared<PitchSequence>();
  std::shared_ptr<Rhythm> r = std::make_shared<Rhythm>(mLength);

  if (mNumNotes <= 0)
    mNumNotes = rand() % 5 + 2;
  if (mNumBeats <= 0)
    mNumBeats = rand() % 2 + 1;

  while ((note * mNumBeats) / mNumNotes < mLength)
  {
    pc->add(std::make_shared<Unison>(std::make_shared<ChordPitch>(pitch++, mOctave)));
    if (pitch >= mNumNotes)
      pitch = 0;

    r->add(RhythmicNote(mNumBeats, mNumNotes, note++));
  }
  return std::make_shared<SequenceIngredient>(pc, r);
}

void ArpeggioSequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "ArpeggioSequenceIngredientBuilder", "Arpeggio", { 
    Describer::intRequirement("length", "Length", 16),
    Describer::intRequirement("numNotes", "Number of Notes (0 for random)", 0),
    Describer::intRequirement("numBeats", "Number of Beats (0 for random)", 0),
    Describer::intRequirement("octave", "Octave", 0),
  });
}
