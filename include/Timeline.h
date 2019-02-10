#pragma once

#include "Tempo.h"
#include "Tonic.h"
#include "Scale.h"
#include "Chord.h"
#include "PitchCollection.h"
#include "Rhythm.h"

#include <string>

class Timeline
{
  private:

  public:
    std::vector<std::string> getTracks();

      void add(Tempo, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Tempo getTempo(std::string track = "default", int beat = -1);

    void add(Tonic, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Tonic getTonic(std::string track = "default", int beat = -1);

   void add(Scale&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Scale& getScale(std::string track = "default", int beat = -1);

    void add(Chord&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Chord& getChord(std::string track = "default", int beat = -1);

    void add(PitchCollection&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    PitchCollection& getPitchCollection(std::string track = "default", int beat = -1);

    void add(Rhythm&, std::string track = "default", int startBeat = -1, int endBeat = -1);
    Rhythm& getRhythm(std::string track = "default", int beat = -1);
};
