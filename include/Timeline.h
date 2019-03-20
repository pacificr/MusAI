#pragma once

#include "Tempo.h"
#include "Tonic.h"
#include "Scale.h"
#include "Chord.h"
#include "PitchSequence.h"
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
    std::map<std::string, TimelineTrack<PitchSequence>> mPitchSequences;
    std::map<std::string, TimelineTrack<Rhythm>> mRhythms;
    std::map<std::string, TimelineTrack<int>> mChannels;

    void addTrackNow(std::string);
  public:
    Timeline();

    void addTrack(std::string);
    void add(std::shared_ptr<Tempo>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Tonic>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Scale>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Chord>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<PitchSequence>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<Rhythm>, std::string track = "default", int startBeat = -1, int endBeat = -1);
    void add(std::shared_ptr<int>, std::string track = "default", int startBeat = -1, int endBeat = -1);

    std::set<std::string> getTracks() const;
    double getLength() const;
    std::vector<Note> getNotes(std::string track);
};
