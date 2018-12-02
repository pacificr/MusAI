#include "../include/ScaleChordProgressionRule.h"

#include "../include/IScaleRule.h"

ScaleChordProgressionRule::ScaleChordProgressionRule(std::vector<int> chordBases)
{
  mChordBases = chordBases;
}

void ScaleChordProgressionRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addFulfillment("ChordProg", this);
}

std::vector<std::vector<int>> ScaleChordProgressionRule::getChords(RuleEnvironment& ruleEnvironment)
{
  std::vector<std::vector<int>> chords;
  std::vector<int> scale = (ruleEnvironment.getRule<IScaleRule>("Scale"))->getScaleDegrees();

  for (auto base : mChordBases)
  {
    std::vector<int> chord;
    chord.push_back(scale[base]);
    chord.push_back(scale[(base + 2) % scale.size()]);
    chord.push_back(scale[(base + 4) % scale.size()]);
    chords.push_back(chord);
  }

  return chords;
}