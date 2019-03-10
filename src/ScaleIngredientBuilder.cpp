#include "../include/ScaleIngredientBuilder.h"

#include "../include/ScaleIngredient.h"

std::shared_ptr<IIngredient> ScaleIngredientBuilder::build()
{
  std::vector<int> degrees;
  if (mScaleTitle == "major" || mScaleTitle == "ionian")
    degrees = {0, 2, 4, 5, 7, 9, 11};
  else if (mScaleTitle == "dorian")
    degrees = {0, 2, 3, 5, 7, 9, 10};
  else if (mScaleTitle == "phrygian")
    degrees = {0, 1, 3, 5, 7, 8, 10};
  else if (mScaleTitle == "lydian")
    degrees = {0, 2, 4, 6, 7, 9, 11};
  else if (mScaleTitle == "myxolydian")
    degrees = {0, 2, 4, 5, 7, 9, 10};
  else if (mScaleTitle == "minor" || mScaleTitle == "aeolian")
    degrees = {0, 2, 3, 5, 7, 8, 10};
  else if (mScaleTitle == "locrian")
    degrees = {0, 1, 3, 5, 6, 8, 10};
  else if (mScaleTitle == "whole tone")
    degrees = {0, 2, 4, 6, 8, 10};
  else if (mScaleTitle == "chromatic")
    degrees = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  else if (mScaleTitle == "major pentatonic")
    degrees = {0, 2, 3, 7, 9};
  else if (mScaleTitle == "minor pentatonic")
    degrees = {0, 3, 5, 7, 10};
  return std::make_shared<ScaleIngredient>(std::make_shared<Scale>(degrees));
}
