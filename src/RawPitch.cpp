#include "../include/RawPitch.h"

int RawPitch::resolve(Scale& scale, Chord& chord) const
{
  return mValue + (12 * mOctave);
}
