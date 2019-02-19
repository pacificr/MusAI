#include "../include/StructuredGenerator.h"

#include "../include/INoteCollection.h"

StructuredGenerator::StructuredGenerator(std::vector<std::shared_ptr<StructureControl>>& controls)
{
  mControls = controls;
  mStructureControl = controls[0];
}

MIDIStream StructuredGenerator::getNext(double time)
{
  MIDIStream signals;

  while (time > mStructureStart + mTimeElapsed)
  {
    INoteCollection& notes = mStructureControl->getNoteCollection();

    for(Note note : notes.getNotes())
    {
      if (note.occursBetween(mTimeElapsed, time - mStructureStart))
      {
        signals.add(note.getNoteOn(mStructureStart));
        signals.add(note.getNoteOff(mStructureStart));
      }
    }

    mTimeElapsed = time - mStructureStart;

    if (time - mStructureStart > notes.getLength())
    {
      mTimeElapsed = 0;
      mStructureStart += notes.getLength();
      mStructureControl = mStructureControl->getNext();
    }
  }

  return signals;
}
