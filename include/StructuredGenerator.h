#pragma once

#include "IGenerator.h"
#include "StructureControl.h"
#include "Note.h"

class StructuredGenerator : IGenerator
{
private:
    StructureControl* mStructureControl;
    double mStructureStart = 0;
    double mTimeElapsed = 0;
public:
    StructuredGenerator(StructureControl&);
    MIDIStream getNext(double time);
    //MIDIStream getNext(int beats);
};