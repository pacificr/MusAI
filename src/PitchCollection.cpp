#include "../include/PitchCollection.h"

void PitchCollection::add(std::shared_ptr<IPitch> pitch)
{
  mPitches.push_back(pitch);
}

IPitch& PitchCollection::getPitch(int index) const
{
  int M = mPitches.size();
  return *mPitches.at(((index % M) + M) % M);
}
