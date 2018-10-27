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

    MIDISignal getNoteOn(long time, int tonic) const;
    MIDISignal getNoteOff(long time, int tonic) const;
};