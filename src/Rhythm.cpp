#include "../include/Rhythm.h"

Rhythm::Rhythm(std::vector<RhythmicNote> notes, int length)
  : mRhythmicNotes(notes), mLength(length){}

std::vector<RhythmicNote> Rhythm::getNotes()
{
  return mRhythmicNotes;
}

int Rhythm::getLength()
{
  return mLength;
}
