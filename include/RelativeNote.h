#pragma once

#include "MIDISignal.h"

class RelativeNote
{
public:
    int mPitch;
    int mBeat;
    int mSubdivision;
    int mDurationBeat;
    int mDurationSubdivision;
};