#pragma once

#include "IPitch.h"

#include <memory>

class Unison
{
  private:
    std::vector<std::shared_ptr<IPitch>> mPitches;
  public:
    Unison() = default;
    Unison(std::shared_ptr<IPitch> pitch)
      {mPitches.push_back(pitch);};
    Unison(std::vector<std::shared_ptr<IPitch>> pitches)
      : mPitches(pitches){};

    Unison& add(std::shared_ptr<IPitch>);
    std::vector<int> resolve(Scale&, Chord&);
};
