#pragma once

#include "Chord.h"
#include "IBuilder.h"

#include "Describer.h"

class ChordBuilder : public IBuilder<Chord>
{
  public:
    std::string mBase;
    std::string mChordTitle;
    int mOctave;
    std::shared_ptr<Chord> build();
    static void registerWith(Describer&);
};
