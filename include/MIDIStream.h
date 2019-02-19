#pragma once

#include "MIDISignal.h"
#include <vector>

class MIDIStream
{
private:
    std::vector<MIDISignal> mSignals;
    unsigned int mCounter = 0;
public:
    void restart();
    void add(MIDISignal);
    bool hasNext() const;
    MIDISignal getNext();
};
