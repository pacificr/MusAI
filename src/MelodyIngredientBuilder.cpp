#include "../include/MelodySequenceIngredientBuilder.h"

#include "../include/SequenceIngredient.h"
#include "../include/ChordPitch.h"

static const std::string RANDOM = "Random";
static const std::string BASSLINE = "Bassline";
static const std::string UPDOWN = "Up and Down";

static const std::string QUARTER_NOTES = "Quarter Notes";
static const std::string HALF_NOTES = "Half Notes";
static const std::string WHOLE_NOTES = "Whole Notes";
static const std::string EIGHTH_NOTES = "Eighth Notes";
static const std::string SIXTEENTH_NOTES = "Sixteenth Notes";
static const std::string QUARTER_NOTE_TRIPLETS = "Quarter Note Triplets";
static const std::string JAZZY = "Jazzy";
static const std::string SYNCOPATED = "Syncopated";

std::shared_ptr<IIngredient> MelodySequenceIngredientBuilder::build()
{
  int pitch = 0;
  int upDownCount = 0;
  bool up;
  std::shared_ptr<PitchSequence> pc = std::make_shared<PitchSequence>();
  std::shared_ptr<Rhythm> rhythm = std::make_shared<Rhythm>(mNumBeats);

  unsigned int numNotes = 0;
  if (mRhythmStyle == QUARTER_NOTES)
    for (unsigned int i = 0; i < mNumBeats; ++i)
    {
      rhythm->add(RhythmicNote(1, 1, i));
      ++numNotes;
    }
  else if (mRhythmStyle == HALF_NOTES)
    for (unsigned int i = 0; i < mNumBeats / 2; ++i)
    {
      rhythm->add(RhythmicNote(2, 1, i));
      ++numNotes;
    }
  else if (mRhythmStyle == WHOLE_NOTES)
    for (unsigned int i = 0; i < mNumBeats / 4; ++i)
    {
      rhythm->add(RhythmicNote(4, 1, i));
      ++numNotes;
    }
  else if (mRhythmStyle == EIGHTH_NOTES)
    for (unsigned int i = 0; i < mNumBeats * 2; ++i)
    {
      rhythm->add(RhythmicNote(1, 2, i));
      ++numNotes;
    }
  else if (mRhythmStyle == SIXTEENTH_NOTES)
    for (unsigned int i = 0; i < mNumBeats * 4; ++i)
    {
      rhythm->add(RhythmicNote(1, 4, i));
      ++numNotes;
    }
  else if (mRhythmStyle == QUARTER_NOTE_TRIPLETS)
    for (unsigned int i = 0; i < mNumBeats * 3; ++i)
    {
      rhythm->add(RhythmicNote(1, 3, i));
      ++numNotes;
    }
  else if (mRhythmStyle == JAZZY)
    for (unsigned int i = 0; i < mNumBeats; i += 2)
    {
      rhythm->add(RhythmicNote(1, 1, i));
      rhythm->add(RhythmicNote(1, 4, 0, i + 1));
      rhythm->add(RhythmicNote(1, 4, 0, i + 1, 3, 4));
      numNotes += 3;
    }
  else if (mRhythmStyle == SYNCOPATED)
    for (unsigned int i = 0; i < mNumBeats; i += 4)
    {
      rhythm->add(RhythmicNote(3, 4, 0, i));
      rhythm->add(RhythmicNote(3, 4, 0, i, 3, 4));
      rhythm->add(RhythmicNote(3, 4, 0, i + 1, 1, 2));
      rhythm->add(RhythmicNote(3, 4, 0, i + 2, 1, 4));
      rhythm->add(RhythmicNote(1, 2, 0, i + 3));
      rhythm->add(RhythmicNote(1, 2, 0, i + 3, 1, 2));
      numNotes += 6;
    }

  for (unsigned int i = 0; i < numNotes; ++i)
  {
    if (mPitchStyle == UPDOWN)
    {
      --upDownCount;

      if (upDownCount < 1)
      {
        upDownCount = rand() % 8;
        up = rand() % 2;
      }
      
      if (up)
        ++pitch;
      else
        --pitch;
    }

    pc->add(std::make_shared<Unison>(std::make_shared<ChordPitch>(pitch, mOctave)));

    if (mPitchStyle == RANDOM)
    {
      pitch += rand() % 3 - 1;
    }
  }

  return std::make_shared<SequenceIngredient>(pc, rhythm);
}

void MelodySequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "MelodySequenceIngredientBuilder", "Melody", {
    Describer::choiceRequirement("pitchStyle", "Pitch Style", {
      RANDOM,
      BASSLINE,
      UPDOWN
    }),
    Describer::choiceRequirement("rhythmStyle", "Rhythm Style", {
      QUARTER_NOTES,
      HALF_NOTES,
      WHOLE_NOTES,
      EIGHTH_NOTES,
      SIXTEENTH_NOTES,
      QUARTER_NOTE_TRIPLETS,
      JAZZY,
      SYNCOPATED
    }),
    Describer::intRequirement("octave", "Octave", 0)
  });
}
