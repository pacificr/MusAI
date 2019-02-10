#include "../include/Tonic.h"

Tonic::Tonic(int pitch, int base)
{
  mPitch = pitch;
  mBase = base;
}

int Tonic::getCenterPitch()
{
  return (mBase * 12) + mPitch;
}
