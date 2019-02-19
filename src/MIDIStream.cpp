#include "../include/MIDIStream.h"

void MIDIStream::restart()
{
  mCounter = 0;
}

void MIDIStream::add(MIDISignal signal)
{
  mSignals.push_back(signal);
}

bool MIDIStream::hasNext() const
{
  return mCounter < mSignals.size();
}

MIDISignal MIDIStream::getNext()
{
  return mSignals[mCounter++];
}
