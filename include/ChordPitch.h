#pragma once

#include "IPitch.h"

class ChordPitch : public IPitch
{
  public:
    ChordPitch(int value = 0, int octave = 0)
      :IPitch(value, octave){};
    int resolve(Scale&, Chord&) const;
};
