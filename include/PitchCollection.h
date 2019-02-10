#pragma once

#include "IPitch.h"

#include <memory>
#include <vector>

class PitchCollection
{
  private:
    std::vector<std::unique_ptr<IPitch>> mPitches;
  public:
    void add(IPitch*);
    IPitch& getPitch(int);
};
