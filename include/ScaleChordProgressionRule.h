#pragma once

#include "IChordProgressionRule.h"

class ScaleChordProgressionRule : public IChordProgressionRule
{
private:
  std::vector<int> mChordBases;
public:
  ScaleChordProgressionRule(std::vector<int>);
  void describe(RuleEnvironment&);
  std::vector<std::vector<int>> getChords(RuleEnvironment&);
};