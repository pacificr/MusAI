#include "../include/StructuredGenerator.h"

MIDIStream StructuredGenerator::getNext(int time)
{
    Note a;
    Note b;
    a.mPitch = 2;
    a.mBeat = 0;
    a.mDurationBeat = 1;
    b.mPitch = 4;
    b.mBeat = 1;
    b.mDurationBeat = 1;
    mNotes.push_back(a);
    mNotes.push_back(b);

    MIDIStream signals;

    for(Note note : mNotes)
    {
        signals.add(note.getNoteOn(4, 45));
        signals.add(note.getNoteOff(4, 45));
    }

    return signals;
}