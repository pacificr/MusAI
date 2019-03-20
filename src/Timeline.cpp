#include "../include/Timeline.h"

#include <math.h>

#include "../include/Logger.h"
#define LOC "timeline"

Timeline::Timeline()
{
  addTrackNow("default");
}

void Timeline::addTrackNow(std::string track)
{
  mTempos.insert(std::pair<std::string, TimelineTrack<Tempo>>(track, TimelineTrack<Tempo>()));
  mTonics.insert(std::pair<std::string, TimelineTrack<Tonic>>(track, TimelineTrack<Tonic>()));
  mScales.insert(std::pair<std::string, TimelineTrack<Scale>>(track, TimelineTrack<Scale>()));
  mChords.insert(std::pair<std::string, TimelineTrack<Chord>>(track, TimelineTrack<Chord>()));
  mPitchSequences.insert(std::pair<std::string, TimelineTrack<PitchSequence>>(track, TimelineTrack<PitchSequence>()));
  mRhythms.insert(std::pair<std::string, TimelineTrack<Rhythm>>(track, TimelineTrack<Rhythm>()));
  mChannels.insert(std::pair<std::string, TimelineTrack<int>>(track, TimelineTrack<int>()));
}

void Timeline::addTrack(std::string track)
{
  if (mTracks.find(track) == mTracks.end() && track != "default")
  {
    mTracks.insert(track);
    addTrackNow(track);
  }
}

void Timeline::add(std::shared_ptr<Tempo> tempo, std::string track, int begin, int end)
{  
  mTempos.at(track).add(TimelineBucket<Tempo>(tempo, begin, end));
}

void Timeline::add(std::shared_ptr<Tonic> tonic, std::string track, int begin, int end)
{
  mTonics.at(track).add(TimelineBucket<Tonic>(tonic, begin, end));
}

void Timeline::add(std::shared_ptr<Scale> scale, std::string track, int begin, int end)
{
  mScales.at(track).add(TimelineBucket<Scale>(scale, begin, end));
}

void Timeline::add(std::shared_ptr<Chord> chord, std::string track, int begin, int end)
{
  mChords.at(track).add(TimelineBucket<Chord>(chord, begin, end));
}

void Timeline::add(std::shared_ptr<PitchSequence> pitches, std::string track, int begin, int end)
{
  mPitchSequences.at(track).add(TimelineBucket<PitchSequence>(pitches, begin, end));
}

void Timeline::add(std::shared_ptr<Rhythm> rhythm, std::string track, int begin, int end)
{
  mRhythms.at(track).add(TimelineBucket<Rhythm>(rhythm, begin, end));
}

void Timeline::add(std::shared_ptr<int> channel, std::string track, int begin, int end)
{
  mChannels.at(track).add(TimelineBucket<int>(channel, begin, end));
}

std::set<std::string> Timeline::getTracks() const
{
  return mTracks;
}

double Timeline::getLength() const
{
  double length = 0;

  for (std::string track : mTracks)
  {
    std::shared_ptr<Rhythm> rhythm = mRhythms.at(track).getObject();
    if (NULL == rhythm)
      rhythm = mRhythms.at("default").getObject();
    std::shared_ptr<Tempo> tempo = mTempos.at(track).getObject();
    if (NULL == tempo)
      tempo = mTempos.at("default").getObject();

    length = std::max(length, tempo->applyTempo(rhythm->getLength()));
  }

  return length;
}

std::vector<Note> Timeline::getNotes(std::string track)
{
  Logger& logger = Logger::instance(); 
  int currentBeat = 0;
  int currentPitch = 0;
  //PitchCollection* oldPitchCollection = NULL;
  std::vector<Note> notes; 

  std::shared_ptr<Rhythm> rhythm = mRhythms.at(track).getObject(currentBeat);
  if (NULL == rhythm)
    rhythm = mRhythms.at("default").getObject(currentBeat);
  if (NULL == rhythm)
    logger.log(LOC, "No rhythm found");

  for (RhythmicNote rhythmicNote : rhythm->getNotes())
  {
    std::shared_ptr<PitchSequence> pitches = mPitchSequences.at(track).getObject(currentBeat + rhythmicNote.getStart());
    if (NULL == pitches)
      pitches = mPitchSequences.at("default").getObject(currentBeat + rhythmicNote.mStartBeat);
    if (NULL == pitches)
      logger.log(LOC, "No pitches found");

    /*if (&pitchCollection != oldPitchCollection) compare starting beats of pitch collection stored in Timeline
    {
      oldPitchCollection = &pitchCollection;
      currentPitch = 0;
    }*/
    std::shared_ptr<Scale> scale = mScales.at(track).getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == scale)
      scale = mScales.at("default").getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == scale)
      logger.log(LOC, "No scale found");

    std::shared_ptr<Chord> chord = mChords.at(track).getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == chord)
      chord = mChords.at("default").getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == chord)
      logger.log(LOC, "no chord found");

    std::shared_ptr<Tempo> tempo = mTempos.at(track).getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == tempo)
      tempo = mTempos.at("default").getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == tempo)
      logger.log(LOC, "No tempo found");

    std::shared_ptr<Tonic> tonic = mTonics.at(track).getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == tonic)
      tonic = mTonics.at("default").getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == tonic)
      logger.log(LOC, "No tonic found");

    std::shared_ptr<int> channel = mChannels.at(track).getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == channel)
      channel = mChannels.at("default").getObject(currentBeat + floor(rhythmicNote.getStart()));
    if (NULL == channel)
      logger.log(LOC, "No channel found");

    double start = tempo->applyTempo(double(currentBeat) + rhythmicNote.getStart());

    double length = tempo->applyTempo(rhythmicNote.getLength());

    for (int pitch : pitches->getUnison(currentPitch).resolve(*scale, *chord))
    {
      Note note(tonic->getCenterPitch() + pitch, start, length, *channel);

      logger.log(LOC, "adding note on track " + track
          + " " + std::to_string(note.mKey)
          + " " + std::to_string(note.mTime)
          + " " + std::to_string(note.mDuration)
          + " " + std::to_string(note.mVelocity)
          + " " + std::to_string(note.mChannel)
      );
      notes.push_back(note);
    }

    ++currentPitch;
  }

  return notes;
}
