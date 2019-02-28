#include "../include/ScalePitch.h"

int ScalePitch::resolve(Scale& scale, Chord&) const
{ 
  return scale.resolveDegree(mValue) + (12 * mOctave);
}
