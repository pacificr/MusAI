#include "../include/ArpeggioSequenceIngredientBuilder.h"

#include "../include/SequenceIngredient.h"
#include "../include/ChordPitch.h"

static const std::string RANDOM = "Random";
static const std::string UP = "Up";
static const std::string DOWN = "Down";

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

  bool goUp = true;
  if (mDirection == DOWN || (mDirection == RANDOM && rand() % 2 == 0))
  {
    goUp = false;
    pitch = mNumNotes;
  }

  while ((note * mOverBeats) / mNumNotes < mNumBeats)
  {
    pc->add(std::make_shared<Unison>(std::make_shared<ChordPitch>(pitch, mOctave)));
    if (goUp)
      ++pitch;
    else
      --pitch;

    if (goUp && pitch >= mNumNotes)
      pitch = 0;
    if (!goUp && pitch <= 0)
      pitch = mNumNotes;

    r->add(RhythmicNote(mOverBeats, mNumNotes, note++));
  }
  return std::make_shared<SequenceIngredient>(pc, r);
}

void ArpeggioSequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "ArpeggioSequenceIngredientBuilder", "Arpeggio", { 
    Describer::intRequirement("numNotes", "Number of Notes (0 for random)", 0),
    Describer::intRequirement("overBeats", "Over Number of Beats (0 for random)", 0),
    Describer::choiceRequirement("direction", "Direction", {
      RANDOM,
      UP,
      DOWN
    }),
    Describer::intRequirement("octave", "Octave", 0),
  });
}
