#pragma once

#include "RhythmicNote.h"

#include <vector>

class Rhythm
{
  private:
    std::vector<RhythmicNote> Notes;
    int length;
  public:
    std::vector<RhythmicNote> getNotes();
};
