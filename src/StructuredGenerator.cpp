#include "../include/StructuredGenerator.h"

#include "../include/INoteProducer.h"

StructuredGenerator::StructuredGenerator(StructureControl& structureControl)
{
    mStructureControl = &structureControl;
}

MIDIStream StructuredGenerator::getNext(double time)
{
    MIDIStream signals;

    while (time > mStructureStart + mTimeElapsed)
    {
        INoteProducer& noteProducer = mStructureControl->getNoteProducer();

        for(Note note : noteProducer.getNotes())
        {
            if (note.occursBetween(mTimeElapsed, time - mStructureStart))
            {
                signals.add(note.getNoteOn(mStructureStart, 45));
                signals.add(note.getNoteOff(mStructureStart, 45));
            }
        }

        mTimeElapsed = time - mStructureStart;

        if (time - mStructureStart > 4)//Length of structure
        {
            mTimeElapsed = 0;
            mStructureStart += 4;
            mStructureControl = &mStructureControl->getNext();
        }
    }

    return signals;
}