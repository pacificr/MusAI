#include "../include/ChordPitch.h"

ChordPitch::ChordPitch(int value, bool strong) : IPitch(value, strong){}

int ChordPitch::resolve(Scale& scale, Chord& chord)
{
  return chord.resolveDegree(mValue, scale);
}
