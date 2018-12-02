#include "../include/BasicHarmonyRule.h"

#include "../include/IChordProgressionRule.h"

void BasicHarmonyRule::describe(RuleEnvironment &ruleEnvironment)
{
  ruleEnvironment.addFulfillment("Harmony", this);
}

std::vector<RelativeNote> BasicHarmonyRule::getRelativeNotes(RuleEnvironment &ruleEnvironment)
{
  auto chordProg = ruleEnvironment.getRule<IChordProgressionRule>("ChordProg");
  auto chords = chordProg->getChords(ruleEnvironment);

  std::vector<RelativeNote> notes;

  unsigned int i = 0;
  for (auto chord : chords)
  {
    RelativeNote a;
    RelativeNote b;
    RelativeNote c;

    a.mPitch = chord[0] - 24;
    a.mBeat = i * 4;
    a.mDurationBeat = 4;

    b.mPitch = chord[1] - 24;
    b.mBeat = i * 4;
    b.mDurationBeat = 4;

    c.mPitch = chord[2] - 24;
    c.mBeat = i * 4;
    c.mDurationBeat = 4;

    notes.push_back(a);
    notes.push_back(b);
    notes.push_back(c);

    ++i;
  }

  return notes;
}

int BasicHarmonyRule::getLength(RuleEnvironment &ruleEnvironment)
{
  auto chordProg = ruleEnvironment.getRule<IChordProgressionRule>("ChordProg");
  return chordProg->getChords(ruleEnvironment).size() * 4;
}