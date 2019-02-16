#include "../include/Timeline.h"

#include "../include/Logger.h"
#define LOC "timeline"

void Timeline::addTrack(std::string track)
{
  if (track == "default")
    Logger::instance().log(LOC, "Cannot ad default or default_timeless");
  mTracks.push_back(track);
  mTempos.insert(std::pair<std::string, TimelineTrack<Tempo>>(track, TimelineTrack<Tempo>()));
  mTonics.insert(std::pair<std::string, TimelineTrack<Tonic>>(track, TimelineTrack<Tonic>()));
  mScales.insert(std::pair<std::string, TimelineTrack<Scale>>(track, TimelineTrack<Scale>()));
  mChords.insert(std::pair<std::string, TimelineTrack<Chord>>(track, TimelineTrack<Chord>()));
  mPitchCollections.insert(std::pair<std::string, TimelineTrack<PitchCollection>>(track, TimelineTrack<PitchCollection>()));
  mRhythms.insert(std::pair<std::string, TimelineTrack<Rhythm>>(track, TimelineTrack<Rhythm>()));
}

std::vector<std::string> Timeline::getTracks()
{
  return mTracks;
}

void Timeline::add(Tempo* tempo, std::string track, int begin, int end)
{  
  mTempos.at(track).add(TimelineBucket<Tempo>(tempo, begin, end));
}

void Timeline::add(Tonic* tonic, std::string track, int begin, int end)
{
  mTonics.at(track).add(TimelineBucket<Tonic>(tonic, begin, end));
}

void Timeline::add(Scale* scale, std::string track, int begin, int end)
{
  mScales.at(track).add(TimelineBucket<Scale>(scale, begin, end));
}

void Timeline::add(Chord* chord, std::string track, int begin, int end)
{
  mChords.at(track).add(TimelineBucket<Chord>(chord, begin, end));
}

void Timeline::add(PitchCollection* pitches, std::string track, int begin, int end)
{
  mPitchCollections.at(track).add(TimelineBucket<PitchCollection>(pitches, begin, end));
}

void Timeline::add(Rhythm* rhythm, std::string track, int begin, int end)
{
  mRhythms.at(track).add(TimelineBucket<Rhythm>(rhythm, begin, end));
}

std::vector<AbsoluteNote> Timeline::getNotes(std::string track)
{
  Logger& logger = Logger::instance(); 
  int currentBeat = 0;
  int currentPitch = 0;
  //PitchCollection* oldPitchCollection = NULL;
  std::vector<AbsoluteNote> notes; 

  Rhythm* rhythm = mRhythms.at(track).getObject(currentBeat);
  if (NULL == rhythm)
    rhythm = mRhythms.at("default").getObject(currentBeat);

  for (RhythmicNote rhythmicNote : rhythm->getNotes())
  {
    PitchCollection* pitches = mPitchCollections.at(track).getObject(currentBeat + rhythmicNote.mStartBeat);
    if (NULL == pitches)
      pitches = mPitchCollections.at("default").getObject(currentBeat + rhythmicNote.mStartBeat);

    /*if (&pitchCollection != oldPitchCollection) compare starting beats of pitch collection stored in Timeline
    {
      oldPitchCollection = &pitchCollection;
      currentPitch = 0;
    }*/
    Scale* scale = mScales.at(track).getObject(currentBeat + rhythmicNote.mStartBeat);
    if (NULL == scale)
      scale = mScales.at("default").getObject(currentBeat + rhythmicNote.mStartBeat);

    Chord* chord = mChords.at(track).getObject(currentBeat + rhythmicNote.mStartBeat);
    if (NULL == chord)
      chord = mChords.at("default").getObject(currentBeat + rhythmicNote.mStartBeat);

    Tempo* tempo = mTempos.at(track).getObject(currentBeat + rhythmicNote.mStartBeat);
    if (NULL == tempo)
      tempo = mTempos.at("default").getObject(currentBeat + rhythmicNote.mStartBeat);

    Tonic* tonic = mTonics.at(track).getObject(currentBeat + rhythmicNote.mStartBeat);
    if (NULL == tonic)
      tonic = mTonics.at("default").getObject(currentBeat + rhythmicNote.mStartBeat);

    AbsoluteNote note(
        tonic->getCenterPitch() + pitches->getPitch(currentPitch).resolve(*scale, *chord),
        tempo->applyTempo(
          double(currentBeat)
          + double(rhythmicNote.mStartBeat)
          + (double(rhythmicNote.mStartValue) / double(rhythmicNote.mStartSubdivision))
        ),
        tempo->applyTempo(double(rhythmicNote.mValue) / double(rhythmicNote.mSubdivision))
    );

    logger.log(LOC, "adding note on track " + track
        + " " + std::to_string(note.mKey)
        + " " + std::to_string(note.mTime)
        + " " + std::to_string(note.mDuration)
        + " " + std::to_string(note.mVelocity)
    );
    notes.push_back(note);

    ++currentPitch;
  }

  return notes;
}
