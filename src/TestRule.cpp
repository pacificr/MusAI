#include "../include/TestRule.h"

#include "../include/IChordProgressionRule.h"

void TestRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addFulfillment("Melody", this);
}

std::vector<RelativeNote> TestRule::getRelativeNotes(RuleEnvironment& ruleEnvironment)
{
  auto chordProg = ruleEnvironment.getRule<IChordProgressionRule>("ChordProg");
  auto chords = chordProg->getChords(ruleEnvironment);
  mLength = chords.size() * 4;
  std::vector<RelativeNote> ret;


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

    ret.push_back(a);
    ret.push_back(b);
    ret.push_back(c);

    for (unsigned int j = 0; j < 4; ++j)
    {
      RelativeNote d;

      d.mPitch = chord[rand() % 3];
      d.mBeat = (i * 4) + j;
      d.mDurationBeat = 1;

      ret.push_back(d);
    }

    ++i;
  }

  return ret;
}

int TestRule::getLength(RuleEnvironment&)
{
  return mLength;
}