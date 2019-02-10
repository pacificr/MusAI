#include "../include/PitchCollection.h"

void PitchCollection::add(IPitch* pitch)
{
  auto pitchPtr = std::unique_ptr<IPitch>(pitch);
  mPitches.push_back(std::move(pitchPtr));
}

IPitch& PitchCollection::getPitch(int index)
{
  int M = mPitches.size();
  return *mPitches.at(((index % M) + M) % M);
}
