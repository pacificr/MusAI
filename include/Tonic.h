#pragma once

class Tonic
{
  public:
    Tonic(int, int base = 4);
    int getCenterPitch() const;
    int mPitch;
    int mBase;
};
