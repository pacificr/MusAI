#pragma once

#include "IPitch.h"

class ScalePitch : public IPitch
{
  public:
    ScalePitch(int = 0);
    int resolve(Scale&, Chord&);
};
