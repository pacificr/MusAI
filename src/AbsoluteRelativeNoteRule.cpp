#include "../include/AbsoluteRelativeNoteRule.h"

AbsoluteRelativeNoteRule::AbsoluteRelativeNoteRule(std::vector<RelativeNote> notes, int length)
{
  mNotes = notes;
  mLength = length;
}

void AbsoluteRelativeNoteRule::describe(RuleEnvironment &) {}

std::vector<RelativeNote> AbsoluteRelativeNoteRule::getRelativeNotes(RuleEnvironment&)
{
  return mNotes;
}

int AbsoluteRelativeNoteRule::getLength(RuleEnvironment&)
{
  return mLength;
}
