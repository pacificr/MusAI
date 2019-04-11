#include "../include/ChordPool.h"

void ChordPool::addChord(std::shared_ptr<Chord> chord)
{
  mChords.push_back(chord);
}

std::shared_ptr<Chord> ChordPool::getChord(int index)
{
  if (index < 0)
    index = rand() % mChords.size();
  return mChords.at(index);
}
