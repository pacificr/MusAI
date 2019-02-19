#include "../include/AbsoluteProgressionRule.h"

void AbsoluteProgressionRule::pushChord(Chord& chord, int length)
{
  mChords.push_back(std::pair<Chord, int>(chord, length));
}

void AbsoluteProgressionRule::applyChords(Timeline& timeline, std::string track) const 
{
  int beat = 0;
  for (std::pair<Chord, int> chord : mChords)
  {
    timeline.add(std::make_shared<Chord>(chord.first), track, beat, beat + chord.second);
    beat += chord.second;
  }
}
