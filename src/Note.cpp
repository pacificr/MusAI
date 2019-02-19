#include "../include/Note.h"

Note::Note(int key, double time, double duration, int velocity)
  : mKey(key), mTime(time), mDuration(duration), mVelocity(velocity) {}

MIDISignal Note::getNoteOn(double offset = 0) const
{
    MIDISignal signal;
    signal.mNoteOn = true;
    signal.mKey = mKey;
    signal.mVelocity = mVelocity;
    signal.mTime = mTime + offset;
    return signal;
}

MIDISignal Note::getNoteOff(double offset = 0) const
{
    MIDISignal signal;
    signal.mKey = mKey;
    signal.mTime = mTime + mDuration + offset;
    return signal;
}

bool Note::occursBetween(double start, double end) const
{
    return start <= mTime && mTime < end;
}
