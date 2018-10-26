#pragma once

#include "IGenerator.h"
#include "Note.h"

class StructuredGenerator : IGenerator
{
private:
    std::vector<Note> mNotes;
public:
    MIDIStream getNext(int time);
};