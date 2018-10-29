#include "../include/Note.h"

MIDISignal Note::getNoteOn(double time, int tonic) const
{
    MIDISignal signal;
    signal.mNoteOn = true;
    signal.mKey = tonic + mPitch;
    signal.mVelocity = 100;
    signal.mTime = time + mBeat;
    return signal;
}

MIDISignal Note::getNoteOff(double time, int tonic) const
{
    MIDISignal signal;
    signal.mKey = tonic + mPitch;
    signal.mTime = time + mBeat + mDurationBeat;
    return signal;
}

bool Note::occursBetween(double start, double end) const
{
    return start <= mBeat && mBeat < end;
}