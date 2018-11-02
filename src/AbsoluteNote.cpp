#include "../include/AbsoluteNote.h"

MIDISignal AbsoluteNote::getNoteOn(double offset = 0) const
{
    MIDISignal signal;
    signal.mNoteOn = true;
    signal.mKey = mKey;
    signal.mVelocity = mVelocity;
    signal.mTime = mTime + offset;
    return signal;
}

MIDISignal AbsoluteNote::getNoteOff(double offset = 0) const
{
    MIDISignal signal;
    signal.mKey = mKey;
    signal.mTime = mTime + mDuration + offset;
    return signal;
}

bool AbsoluteNote::occursBetween(double start, double end) const
{
    return start <= mTime && mTime < end;
}