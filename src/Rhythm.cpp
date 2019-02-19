#include "../include/Rhythm.h"

Rhythm::Rhythm(std::vector<RhythmicNote> notes, int length)
  : mRhythmicNotes(notes), mLength(length){}

std::vector<RhythmicNote> Rhythm::getNotes() const
{
  return mRhythmicNotes;
}

int Rhythm::getLength() const
{
  return mLength;
}
