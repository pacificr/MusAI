#pragma once

#include "RhythmicNote.h"

#include <vector>

class Rhythm
{
  private:
    std::vector<RhythmicNote> mRhythmicNotes;
    int mLength;
  public:
    Rhythm(int);
    void add(RhythmicNote);
    std::vector<RhythmicNote> getNotes() const;
    int getLength() const;
};
