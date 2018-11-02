#pragma once

#include "MIDISignal.h"

class AbsoluteNote
{
public:
  double mTime;
  double mDuration;
  int mKey;
  int mVelocity;

  MIDISignal getNoteOn(double offset) const;
  MIDISignal getNoteOff(double offset) const;
  bool occursBetween(double start, double end) const;
};