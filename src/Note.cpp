#include "../include/Note.h"

MIDISignal Note::getNoteOn(long time, int tonic)
{
    MIDISignal signal;
    signal.mNoteOn = true;
    signal.mKey = tonic + mPitch;
    signal.mVelocity = 100;
    signal.mTime = time + mBeat;
    return signal;
}

MIDISignal Note::getNoteOff(long time, int tonic)
{
    MIDISignal signal;
    signal.mKey = tonic + mPitch;
    signal.mTime = time + mBeat + mDurationBeat;
    return signal;
}