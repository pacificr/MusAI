#include "../include/Unison.h"

Unison& Unison::add(std::shared_ptr<IPitch> pitch)
{
  mPitches.push_back(pitch);
  return *this;
}

std::vector<int> Unison::resolve(Scale& scale, Chord& chord)
{
  std::vector<int> results;
  for (std::shared_ptr<IPitch> pitch : mPitches)
    results.push_back(pitch->resolve(scale, chord));
  return results;
}
