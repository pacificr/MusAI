#include "../include/Rhythm.h"

Rhythm::Rhythm(int length)
  : mLength(length){}

void Rhythm::add(RhythmicNote note)
{
  mRhythmicNotes.push_back(note);
}

std::vector<RhythmicNote> Rhythm::getNotes() const
{
  return mRhythmicNotes;
}

int Rhythm::getLength() const
{
  return mLength;
}
