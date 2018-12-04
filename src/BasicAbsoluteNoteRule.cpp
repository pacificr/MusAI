#include "../include/BasicAbsoluteNoteRule.h"

#include "../include/IRelativeNoteRule.h"
#include "../include/ITonicRule.h"
#include "../include/ISubdivisionRule.h"
#include "../include/ITempoRule.h"

BasicAbsoluteNoteRule::BasicAbsoluteNoteRule(std::string id)
{
  mID = id;
}

void BasicAbsoluteNoteRule::describe(RuleEnvironment& ruleEnvironment){}

std::vector<AbsoluteNote> BasicAbsoluteNoteRule::getAbsoluteNotes(RuleEnvironment& ruleEnvironment)
{
  std::vector<AbsoluteNote> ret;

  auto melody = ruleEnvironment.getRule<IRelativeNoteRule>("Melody_" + mID);
  auto harmony = ruleEnvironment.getRule<IRelativeNoteRule>("Harmony");
  auto tonic = ruleEnvironment.getRule<ITonicRule>("Tonic");
  auto subdivision = ruleEnvironment.getRule<ISubdivisionRule>("Subdivision");
  auto tempo = ruleEnvironment.getRule<ITempoRule>("Tempo");

  for (RelativeNote note : melody->getRelativeNotes(ruleEnvironment))
  {
    AbsoluteNote absoluteNote;
    absoluteNote.mTime = tempo->applyTempo(note.mBeat + subdivision->applyTiming(note.mSubdivision));
    absoluteNote.mDuration = tempo->applyTempo(note.mDurationBeat + subdivision->applyTiming(note.mDurationSubdivision));
    absoluteNote.mKey = tonic->applyTonic(note.mPitch);
    absoluteNote.mVelocity = 100;

    ret.push_back(absoluteNote);
  }

  for (RelativeNote note : harmony->getRelativeNotes(ruleEnvironment))
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
  auto notes = ruleEnvironment.getRule<IRelativeNoteRule>("Melody_" + mID);
  auto tempo = ruleEnvironment.getRule<ITempoRule>("Tempo");

  return tempo->applyTempo(notes->getLength(ruleEnvironment));
}