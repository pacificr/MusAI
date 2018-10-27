#pragma once

#include "IGenerator.h"
#include "StructureControl.h"
#include "Note.h"

class StructuredGenerator : IGenerator
{
private:
    std::shared_ptr<StructureControl> mStructureControl;
public:
    StructuredGenerator(const StructureControl&);
    MIDIStream getNext(int time);
};