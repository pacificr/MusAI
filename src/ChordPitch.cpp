#include "../include/ChordPitch.h"

int ChordPitch::resolve(Scale& scale, Chord& chord) const
{
  return chord.resolveDegree(mValue, scale) + (12 * mOctave);
}
