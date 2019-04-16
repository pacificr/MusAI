#include "../include/TonicIngredientBuilder.h"

#include "../include/TonicIngredient.h"

static const std::string C = "C";
static const std::string CSHARP = "C#";
static const std::string DFLAT = "Db";
static const std::string D = "D";
static const std::string DSHARP = "D#";
static const std::string EFLAT = "Eb";
static const std::string E = "E";
static const std::string F = "F";
static const std::string FSHARP = "F#";
static const std::string GFLAT = "Gb";
static const std::string G = "G";
static const std::string GSHARP = "G#";
static const std::string AFLAT = "Ab";
static const std::string A = "A";
static const std::string ASHARP = "A#";
static const std::string BFLAT = "Bb";
static const std::string B = "B";

static const std::string RANDOM = "random";

std::shared_ptr<IIngredient> TonicIngredientBuilder::build()
{
  int tonic;
  if (mTonicTitle == C)
    tonic = 0;
  else if (mTonicTitle == CSHARP || mTonicTitle == DFLAT)
    tonic = 1;
  else if (mTonicTitle == D)
    tonic = 2;
  else if (mTonicTitle == DSHARP || mTonicTitle == EFLAT)
    tonic = 3;
  else if (mTonicTitle == E)
    tonic = 4;
  else if (mTonicTitle == F)
    tonic = 5;
  else if (mTonicTitle == FSHARP || mTonicTitle == GFLAT)
    tonic = 6;
  else if (mTonicTitle == G)
    tonic = 7;
  else if (mTonicTitle == GSHARP || mTonicTitle == AFLAT)
    tonic = 8;
  else if (mTonicTitle == A)
    tonic = 9;
  else if (mTonicTitle == ASHARP || mTonicTitle == BFLAT)
    tonic = 10;
  else if (mTonicTitle == B)
    tonic = 11;
  else
  {
    tonic = rand() % 12;
    mOctave -= rand() %2;
  }

  return std::make_shared<TonicIngredient>(tonic, mOctave);
}

void TonicIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilderMultiple({"IngredientBuilder", "GlobalTonic"}, "TonicIngredientBuilder", "Tonic", {
    Describer::choiceRequirement("tonic", "Tonic", {
      RANDOM,
      C,
      CSHARP,
      DFLAT,
      D,
      DSHARP,
      EFLAT,
      E,
      F,
      FSHARP,
      GFLAT,
      G,
      GSHARP,
      AFLAT,
      A,
      ASHARP,
      BFLAT,
      B
    }),
    Describer::intRequirement("octave", "Octave", 5)
  });
}
