#pragma once

class Tonic
{
  public:
    Tonic(int, int base = 5);
    int getCenterPitch() const;
    int mPitch;
    int mBase;
};
