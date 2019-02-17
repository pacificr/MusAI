#pragma once

#include "IPitch.h"

#include <memory>
#include <vector>

class PitchCollection
{
  private:
    std::vector<std::shared_ptr<IPitch>> mPitches;
  public:
    void add(std::shared_ptr<IPitch>);
    IPitch& getPitch(int);
};
