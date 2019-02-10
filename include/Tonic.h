#pragma once

class Tonic
{
  public:
    Tonic(int, int base = 4);
    int getCenterPitch();
    int mPitch;
    int mBase;
};
