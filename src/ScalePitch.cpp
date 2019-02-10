#include "../include/ScalePitch.h"

ScalePitch::ScalePitch(int value) : IPitch(value){}

int ScalePitch::resolve(Scale& scale, Chord& chord)
{ 
  return scale.resolveDegree(mValue);
}
