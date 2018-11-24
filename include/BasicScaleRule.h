#pragma once

#include "IScaleRule.h"

enum class SCALE {MAJOR, MINOR, IONIAN, DORIAN, PHRYGIAN, LYDIAN, MIXOLYDIAN, AEOLIAN, LOCRIAN};

class BasicScaleRule : public IScaleRule
{
private:
  std::vector<int> mScaleDegrees;
public:
  BasicScaleRule(SCALE);
  void describe(RuleEnvironment&);
  std::vector<int> getScaleDegrees();
};