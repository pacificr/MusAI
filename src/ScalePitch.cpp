#include "../include/ScalePitch.h"

ScalePitch::ScalePitch(int value) : IPitch(value){}

int ScalePitch::resolve(Scale& scale, Chord& chord) const
{ 
  return scale.resolveDegree(mValue);
}
