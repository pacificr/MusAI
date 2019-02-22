#pragma once

#include "Chord.h"

class IPitch
{
  public:
    int mValue;
    int mOctave;

    IPitch(int value, int octave)
      : mValue(value), mOctave(octave){};
    virtual ~IPitch() = default;

    virtual int resolve(Scale&, Chord&) const = 0;
};
