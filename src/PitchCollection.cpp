#include "../include/PitchCollection.h"

PitchCollection::PitchCollection(std::vector<IPitch*> pitches)
{
  mPitches = pitches;
}

IPitch& PitchCollection::getPitch(int index)
{
  return *mPitches.at(index % mPitches.size());
}
