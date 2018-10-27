#include "../include/StructuredGenerator.h"

#include "../include/INoteProducer.h"

StructuredGenerator::StructuredGenerator(const StructureControl& structureControl)
{
    mStructureControl = std::make_shared<StructureControl>(structureControl);
}

MIDIStream StructuredGenerator::getNext(int time)
{
    INoteProducer& noteProducer = mStructureControl->getNoteProducer();

    MIDIStream signals;

    for(Note note : noteProducer.getNotes())
    {
        signals.add(note.getNoteOn(4, 45));
        signals.add(note.getNoteOff(4, 45));
    }

    return signals;
}