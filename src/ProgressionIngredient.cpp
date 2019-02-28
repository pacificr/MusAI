#include "../include/ProgressionIngredient.h"

void ProgressionIngredient::pushChord(std::shared_ptr<Chord> chord, int length)
{
  mChords.push_back(std::pair<std::shared_ptr<Chord>, int>(chord, length));
}

void ProgressionIngredient::apply(Timeline& timeline, std::string track)
{
  int beat = 0;
  for (std::pair<std::shared_ptr<Chord>, int> chord : mChords)
  {
    timeline.add(chord.first, track, beat, beat + chord.second);
    beat += chord.second;
  }
}
