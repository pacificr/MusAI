#pragma once

#include "MIDISignal.h"

class Note
{
public:
    int mPitch;
    int mBeat;
    int mSubdivision;
    int mDurationBeat;
    int mDurationSubdivision;
    //int velocity;

    MIDISignal getNoteOn(double time, int tonic) const;
    MIDISignal getNoteOff(double time, int tonic) const;
    bool occursBetween(double start, double end) const;
};