#include "../include/Scale.h"

Scale::Scale(std::vector<int> scaleDegrees)
{
  mScaleDegrees = scaleDegrees;
}

int Scale::resolveDegree(int index)
{
  int M = mScaleDegrees.size();
  int degree = mScaleDegrees.at(((index % M) + M) %M);
  int octave = index / (int)mScaleDegrees.size();
  if (index < 0 && degree != 0)
    --octave;
  return degree + octave * 12;
}

unsigned int Scale::size()
{
  return mScaleDegrees.size();
}
