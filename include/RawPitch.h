#pragma once

#include "IPitch.h"

class RawPitch : public IPitch
{
  public:
    RawPitch(int value = 0, int octave = 0)
      :IPitch(value, octave){};
    int resolve(Scale&, Chord&) const;
};
