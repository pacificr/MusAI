#pragma once

#include "Scale.h"

#include <vector>

class Chord
{
  private:
    std::vector<int> mChordDegrees;
  public:
    bool mUseScale;

    Chord(const std::vector<int>, bool useScale = true);
    int resolveDegree(int, Scale&) const;
};
