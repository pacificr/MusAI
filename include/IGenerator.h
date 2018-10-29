#pragma once

#include "MIDIStream.h"

class IGenerator
{
public:
    virtual MIDIStream getNext(double time) = 0;
};