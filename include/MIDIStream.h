#pragma once

#include "MIDISignal.h"
#include <vector>

class MIDIStream
{
private:
    std::vector<MIDISignal> mSignals;
    unsigned int counter = 0;
public:
    void restart() {counter = 0;};
    void add(MIDISignal);
    bool hasNext();
    MIDISignal getNext();
};