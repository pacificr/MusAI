#include "../include/ChordBuilder.h"

static const std::string ONE = "I";
static const std::string TWO = "II";
static const std::string THREE = "III";
static const std::string FOUR = "IV";
static const std::string FIVE = "V";
static const std::string SIX = "VI";
static const std::string SEVEN = "VII";
static const std::string RANDOM = "Random";

static const std::string MAJOR = "Maj";
static const std::string MINOR = "min";
static const std::string DIMINISHED = "dim";
static const std::string MAJOR_SEVENTH = "M7";
static const std::string MINOR_SEVENTH = "m7";
static const std::string DIMINISHED_SEVENTH = "dim7";
static const std::string DOMINANT_SEVENTH = "Dominant7";
static const std::string OPEN_FOURTH = "Open Fourth";
static const std::string OPEN_FIFTH = "Open Fifth";
static const std::string SUSPENDED_2 = "Sus2";
static const std::string SUSPENDED_4 = "Sus4";
static const std::string AUGMENTED = "Aug";
static const std::string DOMINANT_NINTH = "Dominant9";
static const std::string ADD_9 = "Add9";
static const std::string ELEVENTH = "Eleventh";
static const std::string THIRTEENTH = "Thirteenth";

std::shared_ptr<Chord> ChordBuilder::build()
{
  int base = 0;
  if (mBase == TWO)
    base = 1;
  else if (mBase == THREE)
    base = 2;
  else if (mBase == FOUR)
    base = 3;
  else if (mBase == FIVE)
    base = 4;
  else if (mBase == SIX)
    base = 5;
  else if (mBase == SEVEN)
    base = 6;
  else if (mBase == RANDOM)
    base = rand() % 7;

  std::vector<int> degrees;
  if (mChordTitle == MAJOR)
    degrees = {0, 4, 7};
  else if (mChordTitle == MINOR)
    degrees = {0, 3, 7};
  else if (mChordTitle == DIMINISHED)
    degrees = {0, 3, 6};
  else if (mChordTitle == MAJOR_SEVENTH)
    degrees = {0, 4, 7, 11};
  else if (mChordTitle == MINOR_SEVENTH)
    degrees = {0, 3, 7, 10};
  else if (mChordTitle == DIMINISHED_SEVENTH)
    degrees = {0, 3, 6, 9};
  else if (mChordTitle == DOMINANT_SEVENTH)
    degrees = {0, 4, 7, 10};
  else if (mChordTitle == OPEN_FOURTH)
    degrees = {0, 5};
  else if (mChordTitle == OPEN_FIFTH)
    degrees = {0, 7};
  else if (mChordTitle == SUSPENDED_2)
    degrees = {0, 2, 7};
  else if (mChordTitle == SUSPENDED_4)
    degrees = {0, 5, 7};
  else if (mChordTitle == AUGMENTED)
    degrees = {0, 4, 8};
  else if (mChordTitle == DOMINANT_NINTH)
    degrees = {0, 4, 10, 14};
  else if (mChordTitle == ADD_9)
    degrees = {0, 4, 7, 14};
  else if (mChordTitle == ELEVENTH)
    degrees = {0, 10, 14, 17};
  else if (mChordTitle == THIRTEENTH)
    degrees = {0, 4, 10, 21};

  for (unsigned int i = 0; i < degrees.size(); ++i)
    degrees[i] = degrees[i] + mOctave * 12;

  return std::make_shared<Chord>(degrees, false, base);
}

void ChordBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("ChordBuilder", "ChordBuilder", "Select", {
    Describer::choiceRequirement("base", "Base", {
      ONE,
      TWO,
      THREE,
      FOUR,
      FIVE,
      SIX,
      SEVEN,
      RANDOM
    }),
    Describer::choiceRequirement("chordTitle", "Chord", {
      MAJOR,
      MINOR,
      DIMINISHED,
      MAJOR_SEVENTH,
      MINOR_SEVENTH,
      DIMINISHED_SEVENTH,
      DOMINANT_SEVENTH,
      SUSPENDED_2,
      SUSPENDED_4,
      AUGMENTED,
      DOMINANT_NINTH,
      ADD_9,
      ELEVENTH,
      THIRTEENTH
    }),
    Describer::intRequirement("octave", "Octave", 0)
  });
}
