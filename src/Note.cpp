#include "../include/Note.h"

Note::Note(int key, double time, double duration, int channel, int velocity)
  : mKey(key), mTime(time), mDuration(duration), mChannel(channel), mVelocity(velocity) {}

MIDISignal Note::getNoteOn(double offset = 0) const
{
    MIDISignal signal;
    signal.mNoteOn = true;
    signal.mKey = mKey;
    signal.mVelocity = mVelocity;
    signal.mTime = mTime + offset;
    signal.mChannel = mChannel;
    return signal;
}

MIDISignal Note::getNoteOff(double offset = 0) const
{
    MIDISignal signal;
    signal.mKey = mKey;
    signal.mTime = mTime + mDuration + offset;
    signal.mChannel = mChannel;
    return signal;
}

bool Note::occursBetween(double start, double end) const
{
    return start <= mTime && mTime < end;
}
