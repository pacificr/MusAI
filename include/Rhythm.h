#pragma once

#include "RhythmicNote.h"

#include <vector>

class Rhythm
{
  private:
    std::vector<RhythmicNote> mRhythmicNotes;
    int mLength;
  public:
    Rhythm(std::vector<RhythmicNote>, int);
    std::vector<RhythmicNote> getNotes();
    int getLength();
};
