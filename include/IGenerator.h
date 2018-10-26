#pragma once

#include "MIDIStream.h"

class IGenerator
{
public:
    virtual MIDIStream getNext(int time) = 0;
};