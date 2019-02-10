#pragma once

#include "IPitch.h"

class ChordPitch : public IPitch
{
  public:
    ChordPitch(int = 0);
    int resolve(Scale&, Chord&);
};
