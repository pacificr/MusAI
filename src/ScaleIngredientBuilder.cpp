#include "../include/ScaleIngredientBuilder.h"

#include "../include/ScaleIngredient.h"

static const std::string MAJOR = "major";
static const std::string IONIAN = "ionian";
static const std::string DORIAN = "dorian";
static const std::string PHRYGIAN = "phrygian";
static const std::string LYDIAN = "lydian";
static const std::string MYXOLYDIAN = "myxolydian";
static const std::string MINOR = "minor";
static const std::string AEOLIAN = "aeolian";
static const std::string LOCRIAN = "locrian";
static const std::string WHOLE_TONE = "whole tone";
static const std::string CHROMATIC = "chromatic";
static const std::string MAJOR_PENTATONIC = "major pentatonic";
static const std::string MINOR_PENTATONIC = "minor pentatonic";

std::shared_ptr<IIngredient> ScaleIngredientBuilder::build()
{
  std::vector<int> degrees;
  if (mScaleTitle == MAJOR || mScaleTitle == IONIAN)
    degrees = {0, 2, 4, 5, 7, 9, 11};
  else if (mScaleTitle == DORIAN)
    degrees = {0, 2, 3, 5, 7, 9, 10};
  else if (mScaleTitle == PHRYGIAN)
    degrees = {0, 1, 3, 5, 7, 8, 10};
  else if (mScaleTitle == LYDIAN)
    degrees = {0, 2, 4, 6, 7, 9, 11};
  else if (mScaleTitle == MYXOLYDIAN)
    degrees = {0, 2, 4, 5, 7, 9, 10};
  else if (mScaleTitle == MINOR || mScaleTitle == AEOLIAN)
    degrees = {0, 2, 3, 5, 7, 8, 10};
  else if (mScaleTitle == LOCRIAN)
    degrees = {0, 1, 3, 5, 6, 8, 10};
  else if (mScaleTitle == WHOLE_TONE)
    degrees = {0, 2, 4, 6, 8, 10};
  else if (mScaleTitle == CHROMATIC)
    degrees = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  else if (mScaleTitle == MAJOR_PENTATONIC)
    degrees = {0, 2, 3, 7, 9};
  else if (mScaleTitle == MINOR_PENTATONIC)
    degrees = {0, 3, 5, 7, 10};
  return std::make_shared<ScaleIngredient>(std::make_shared<Scale>(degrees));
}

void ScaleIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "ScaleIngredientBuilder", "Scale", {
    Describer::choiceRequirement("scale", "Scale", {
      MAJOR,
      MINOR,
      MAJOR_PENTATONIC,
      MINOR_PENTATONIC,
      WHOLE_TONE,
      CHROMATIC,
      IONIAN,
      DORIAN,
      PHRYGIAN,
      LYDIAN,
      MYXOLYDIAN,
      AEOLIAN,
      LOCRIAN
    })
  });
}
