#pragma once

#include "MIDISignal.h"

class Note
{
public:
  int mKey;
  double mTime;
  double mDuration;
  int mChannel;
  int mVelocity;


  Note(int key = 0, double time = 0, double duration = 1, int channel = 0, int velocity = 100);
  MIDISignal getNoteOn(double offset) const;
  MIDISignal getNoteOff(double offset) const;
  bool occursBetween(double start, double end) const;
};
