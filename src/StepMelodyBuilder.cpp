#include "../include/StepMelodyBuilder.h"

#include "../include/AbsoluteRelativeNoteRule.h"
#include "../include/IChordProgressionRule.h"

void StepMelodyBuilder::describe(RuleEnvironment &ruleEnvironment)
{
  ruleEnvironment.addBuilds("Melody", this);
}

IRule *StepMelodyBuilder::build(RuleEnvironment &ruleEnvironment)
{
  auto chordProg = ruleEnvironment.getRule<IChordProgressionRule>("ChordProg");
  auto chords = chordProg->getChords(ruleEnvironment);
  int length = chords.size() * 4;
  std::vector<RelativeNote> notes;

  int current = 8;

  unsigned int i = 0;
  for (auto chord : chords)
  {
    for (unsigned int j = 0; j < 4; ++j)
    {
      RelativeNote a;
      std::vector<int> possibleNotes;
      for (int i = -2; i < 3; ++i)
      {
        possibleNotes.push_back(chord[0] + (i * 12));
        possibleNotes.push_back(chord[1] + (i * 12));
        possibleNotes.push_back(chord[2] + (i * 12));
      }

      a.mPitch = possibleNotes[current];
      a.mBeat = (i * 4) + j;
      a.mDurationBeat = 1;

      notes.push_back(a);

      current += rand() % 3 - 1;
    }

    ++i;
  }

  return new AbsoluteRelativeNoteRule(notes, length);
}