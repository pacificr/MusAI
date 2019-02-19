#include "../include/ChordPitch.h"

ChordPitch::ChordPitch(int value) : IPitch(value){}

int ChordPitch::resolve(Scale& scale, Chord& chord) const
{
  return chord.resolveDegree(mValue, scale);
}
