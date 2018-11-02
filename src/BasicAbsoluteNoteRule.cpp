#include "../include/BasicAbsoluteNoteRule.h"

#include "../include/IRelativeNoteRule.h"

void BasicAbsoluteNoteRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("TestA", this);
}

std::vector<AbsoluteNote> BasicAbsoluteNoteRule::getAbsoluteNotes(RuleEnvironment& ruleEnvironment)
{
  std::vector<AbsoluteNote> ret;

  IRelativeNoteRule* notes = (IRelativeNoteRule*)ruleEnvironment.getRule("Test");

  for (RelativeNote note : notes->getRelativeNotes())
  {
    AbsoluteNote absoluteNote;
    absoluteNote.mTime = note.mBeat;
    absoluteNote.mDuration = note.mDurationBeat;
    absoluteNote.mKey = note.mPitch;
    absoluteNote.mVelocity = 100;

    ret.push_back(absoluteNote);
  }

  return ret;
}