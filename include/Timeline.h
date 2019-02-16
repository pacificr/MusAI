#pragma once

#include "Tempo.h"
#include "Tonic.h"
#include "Scale.h"
#include "Chord.h"
#include "PitchCollection.h"
#include "Rhythm.h"
#include "AbsoluteNote.h"
#include "TimelineTrack.h"

#include <map>
#include <string>

class Timeline
{
  private:
    std::vector<std::string> mTracks;

    std::map<std::string, TimelineTrack<Tempo>> mTempos;
    std::map<std::string, TimelineTrack<Tonic>> mTonics;
    std::map<std::string, TimelineTrack<Scale>> mScales;
    std::map<std::string, TimelineTrack<Chord>> mChords;
    std::map<std::string, TimelineTrack<PitchCollection>> mPitchCollections;
    std::map<std::string, TimelineTrack<Rhythm>> mRhythms;
  public:
    void addTrack(std::string);
    std::vector<std::string> getTracks();

    void add(Tempo*, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(Tonic*, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(Scale*, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(Chord*, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(PitchCollection*, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(Rhythm*, std::string track = "default", int startBeat = -1, int endBeat = -1);

    std::vector<AbsoluteNote> getNotes(std::string track);
};
