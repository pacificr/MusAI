#pragma once

#include "Unison.h"

#include <memory>
#include <vector>

class PitchCollection
{
  private:
    std::vector<std::shared_ptr<Unison>> mPitches;
  public:
    PitchCollection& add(std::shared_ptr<Unison>);
    Unison& getUnison(int) const;
};
