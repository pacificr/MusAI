#pragma once

#include "IPitch.h"

class ScalePitch : public IPitch
{
  public:
    ScalePitch(int value = 0, int octave = 0)
      : IPitch(value, octave){};
    int resolve(Scale&, Chord&) const;
};
