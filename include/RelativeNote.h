#pragma once

#include "MIDISignal.h"

class RelativeNote
{
public:
    int mPitch = 0;
    unsigned int mBeat = 0;
    unsigned int mSubdivision = 0;
    unsigned int mDurationBeat = 0;
    unsigned int mDurationSubdivision = 0;
};