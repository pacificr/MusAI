#pragma once

#include "Unison.h"

#include <memory>
#include <vector>

class PitchSequence
{
  private:
    std::vector<std::shared_ptr<Unison>> mPitches;
  public:
    PitchSequence& add(std::shared_ptr<Unison>);
    Unison& getUnison(int) const;
};
