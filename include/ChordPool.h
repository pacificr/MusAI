#pragma once

#include "Chord.h"

#include <memory>

class ChordPool
{
  private:
    std::vector<std::shared_ptr<Chord>> mChords;
  public:
    void addChord(std::shared_ptr<Chord>);
    std::shared_ptr<Chord> getChord(int index = -1);
};
