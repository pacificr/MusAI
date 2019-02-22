#include "../include/PitchCollection.h"

PitchCollection& PitchCollection::add(std::shared_ptr<Unison> pitch)
{
  mPitches.push_back(pitch);
  return *this;
}

Unison& PitchCollection::getUnison(int index) const
{
  int M = mPitches.size();
  return *mPitches.at(((index % M) + M) % M);
}
