#include "../include/BasicAbsoluteNoteRule.h"

#include "../include/IRelativeNoteRule.h"
#include "../include/ITonicRule.h"
#include "../include/ISubdivisionRule.h"
#include "../include/ITempoRule.h"

void BasicAbsoluteNoteRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("TestA", this);
}

std::vector<AbsoluteNote> BasicAbsoluteNoteRule::getAbsoluteNotes(RuleEnvironment& ruleEnvironment)
{
  std::vector<AbsoluteNote> ret;

  IRelativeNoteRule* notes = (IRelativeNoteRule*)ruleEnvironment.getRule("Test");
  ITonicRule* tonic = (ITonicRule*)ruleEnvironment.getRule("Tonic");
  ISubdivisionRule* subdivision = (ISubdivisionRule*)ruleEnvironment.getRule("Subdivision");
  ITempoRule* tempo = (ITempoRule*)ruleEnvironment.getRule("Tempo");

  for (RelativeNote note : notes->getRelativeNotes(ruleEnvironment))
  {
    AbsoluteNote absoluteNote;
    absoluteNote.mTime = tempo->applyTempo(note.mBeat + subdivision->applyTiming(note.mSubdivision));
    absoluteNote.mDuration = tempo->applyTempo(note.mDurationBeat + subdivision->applyTiming(note.mDurationSubdivision));
    absoluteNote.mKey = tonic->applyTonic(note.mPitch);
    absoluteNote.mVelocity = 100;

    ret.push_back(absoluteNote);
  }

  return ret;
}

double BasicAbsoluteNoteRule::getLength(RuleEnvironment& ruleEnvironment)
{
  IRelativeNoteRule* notes = (IRelativeNoteRule*)ruleEnvironment.getRule("Test");
  ITempoRule* tempo = (ITempoRule*)ruleEnvironment.getRule("Tempo");

  return tempo->applyTempo(notes->getLength());
}