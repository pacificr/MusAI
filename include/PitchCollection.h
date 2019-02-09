#pragma once

#include "IPitch.h"

#include <vector>

class PitchCollection
{
  private:
    std::vector<IPitch*> mPitches;
  public:
    PitchCollection(std::vector<IPitch*>);
    IPitch& getPitch(int);
};
