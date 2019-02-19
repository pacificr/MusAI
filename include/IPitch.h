#pragma once

#include "Chord.h"

class IPitch
{
  public:
    int mValue;

    IPitch(int value) : mValue(value){};
    virtual ~IPitch() = default;
    virtual int resolve(Scale&, Chord&) const = 0;
};
