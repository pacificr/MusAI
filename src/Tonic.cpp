#include "../include/Tonic.h"

Tonic::Tonic(int pitch, int base)
{
  mPitch = pitch;
  mBase = base;
}

int Tonic::getCenterPitch() const
{
  return (mBase * 12) + mPitch;
}
