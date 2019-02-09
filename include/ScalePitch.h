#pragma once

#include "IPitch.h"

class ScalePitch : public IPitch
{
  public:
    ScalePitch(int = 0, bool = true);
    int resolve(Scale&, Chord&);
};
