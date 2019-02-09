#include "../include/ScalePitch.h"

ScalePitch::ScalePitch(int value, bool strong) : IPitch(value, strong){}

int ScalePitch::resolve(Scale& scale, Chord& chord)
{ 
  return scale.resolveDegree(mValue);
}
