#include "../include/StructuredGenerator.h"

#include "../include/IAbsoluteNoteRule.h"

StructuredGenerator::StructuredGenerator(RuleEnvironment* ruleEnvironment, StructureControl* structureControl)
{
  mRuleEnvironment = ruleEnvironment;
  mStructureControl = structureControl;
}

StructuredGenerator::~StructuredGenerator()
{
  delete mStructureControl;
}

MIDIStream StructuredGenerator::getNext(double time)
{
  MIDIStream signals;

  while (time > mStructureStart + mTimeElapsed)
  {
    IAbsoluteNoteRule& notes = mStructureControl->getNoteRule();

    for(AbsoluteNote note : notes.getAbsoluteNotes(*mRuleEnvironment))
    {
      if (note.occursBetween(mTimeElapsed, time - mStructureStart))
      {
        signals.add(note.getNoteOn(mStructureStart));
        signals.add(note.getNoteOff(mStructureStart));
      }
    }

    mTimeElapsed = time - mStructureStart;

    if (time - mStructureStart > notes.getLength(*mRuleEnvironment))
    {
      mTimeElapsed = 0;
      mStructureStart += notes.getLength(*mRuleEnvironment);
      mStructureControl = &mStructureControl->getNext(*mRuleEnvironment);
    }
  }

  return signals;
}