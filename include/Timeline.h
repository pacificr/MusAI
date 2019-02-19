#pragma once

#include "Tempo.h"
#include "Tonic.h"
#include "Scale.h"
#include "Chord.h"
#include "PitchCollection.h"
#include "Rhythm.h"
#include "Note.h"
#include "TimelineTrack.h"

#include <map>
#include <set>
#include <string>

class Timeline
{
  private:
    std::set<std::string> mTracks;

    std::map<std::string, TimelineTrack<Tempo>> mTempos;
    std::map<std::string, TimelineTrack<Tonic>> mTonics;
    std::map<std::string, TimelineTrack<Scale>> mScales;
    std::map<std::string, TimelineTrack<Chord>> mChords;
    std::map<std::string, TimelineTrack<PitchCollection>> mPitchCollections;
    std::map<std::string, TimelineTrack<Rhythm>> mRhythms;

    void addTrackNow(std::string);
  public:
    Timeline();
    void addTrack(std::string);
    std::set<std::string> getTracks() const;

    void add(std::shared_ptr<Tempo>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Tonic>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Scale>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Chord>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<PitchCollection>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Rhythm>, std::string track = "default", int startBeat = -1, int endBeat = -1);

    std::vector<Note> getNotes(std::string track);
};
