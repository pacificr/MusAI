#include "../include/PitchSequence.h"

PitchSequence& PitchSequence::add(std::shared_ptr<Unison> pitch)
{
  mPitches.push_back(pitch);
  return *this;
}

Unison& PitchSequence::getUnison(int index) const
{
  int M = mPitches.size();
  return *mPitches.at(((index % M) + M) % M);
}
