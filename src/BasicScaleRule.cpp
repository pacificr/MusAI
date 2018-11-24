#include "../include/BasicScaleRule.h"

BasicScaleRule::BasicScaleRule(SCALE scale)
{
  mScaleDegrees = {0, 2, 4, 5, 7, 9, 11};
  int offset = 0;
  switch(scale)
  {
  case SCALE::DORIAN:
    offset = 2;
    break;
  case SCALE::PHRYGIAN:
    offset = 4;
    break;
  case SCALE::LYDIAN:
    offset = 5;
    break;
  case SCALE::MIXOLYDIAN:
    offset = 7;
    break;
  case SCALE::AEOLIAN:
  case SCALE::MINOR:
    offset = 9;
    break;
  case SCALE::LOCRIAN:
    offset = 11;
    break;
  default:
    break;
  }

  for (unsigned int i = 0; i < mScaleDegrees.size(); ++i)
    mScaleDegrees[i] = (mScaleDegrees[i] + offset) % 12;
};

void BasicScaleRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Scale", this);
}

std::vector<int> BasicScaleRule::getScaleDegrees()
{
  return mScaleDegrees;
}