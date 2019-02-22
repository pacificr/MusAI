#include "../include/Chord.h"

Chord::Chord(std::vector<int> chordDegrees, bool useScale)
{
  mChordDegrees = chordDegrees;
  mUseScale = useScale;
}

int Chord::resolveDegree(int index, Scale& scale) const
{
  int M = mChordDegrees.size();
  int degree = mChordDegrees.at(((index % M) + M ) % M);
  int limit = index / (int)mChordDegrees.size();
  if (index < 0 && degree != 0)
    --limit;

  if (mUseScale)
  {
    return scale.resolveDegree(degree + limit * scale.size());
  }
  else
  {
    return degree + limit * 12;
  }
}

unsigned int Chord::size() const
{
  return mChordDegrees.size();
}
