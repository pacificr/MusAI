#pragma once

#include "Chord.h"

class IPitch
{
  public:
    int mValue;

    IPitch(int value) : mValue(value){};
    virtual int resolve(Scale&, Chord&) = 0;
    virtual ~IPitch() = default;
};
