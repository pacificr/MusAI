#pragma once

#include "Scale.h"
#include "Chord.h"
#include "PitchCollection.h"
#include "Rhythm.h"

#include <string>

class Timeline
{
  private:

  public:
    void add(Scale&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Scale& getScale(std::string track = "default", int beat = -1);

    void add(Chord&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Chord& getChord(std::string track = "default", int beat = -1);

    void add(PitchCollection&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    PitchCollection& getPitchCollection(std::string track = "default", int beat = -1);

    void add(Rhythm&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Rhythm& getRhythm(std::string track = "default", int beat = -1);
};
