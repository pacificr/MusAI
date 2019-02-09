#pragma once

#include "Chord.h"

class IPitch
{
  public:
    int mValue;
    int mStrong;

    IPitch(int value, bool strong) : mValue(value), mStrong(strong){};
    virtual int resolve(Scale&, Chord&) = 0;
    ~IPitch() = default;
};
