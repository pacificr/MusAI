#include "../include/MIDIStream.h"

void MIDIStream::add(MIDISignal signal)
{
  mSignals.push_back(signal);
}

bool MIDIStream::hasNext()
{
  return counter < mSignals.size();
}

MIDISignal MIDIStream::getNext()
{
  return mSignals[counter++];
}