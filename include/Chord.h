#pragma once

#include "Scale.h"

#include <vector>

class Chord
{
  private:
    std::vector<int> mChordDegrees;
  public:
    bool mUseScale;
    int mStartingScaleDegree;

    Chord(const std::vector<int>, bool useScale = true, int startingScaleDegree = 0);
    int resolveDegree(int, Scale&) const;
    unsigned int size() const;
};
