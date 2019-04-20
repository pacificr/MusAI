#include "../include/Timeline.h"

#include "../include/ChannelIngredientBuilder.h"
#include "../include/ProgressionIngredientBuilder.h"
#include "../include/MelodySequenceIngredientBuilder.h"

#include <math.h>

#include "../include/Logger.h"
#define LOC "timeline"

std::shared_ptr<IIngredient> Timeline::gDefaultTempo = nullptr;
std::shared_ptr<IIngredient> Timeline::gDefaultTonic = nullptr;
std::shared_ptr<IIngredient> Timeline::gDefaultScale = nullptr;

Timeline::Timeline(int length, bool useSlowest)
  : mLength(length), mUseSlowestTempo(useSlowest)
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
  std::shared_ptr<Tempo> tempo = mTempos.at("default").getObject();

  for (std::string track : mTracks)
  {
    std::shared_ptr<Tempo> checking = mTempos.at(track).getObject();
    if (NULL != checking)
    {
      if ((mUseSlowestTempo && checking->mBpm < tempo->mBpm)
          || (!mUseSlowestTempo && checking->mBpm > tempo->mBpm))
      {
        tempo = checking;
      }
    }
  }
  return tempo->applyTempo(mLength);
}

std::vector<Note> Timeline::getNotes(std::string track)
{
  Logger& logger = Logger::instance(); 
  int currentBeat = 0;
  int currentPitch = 0;
  //PitchCollection* oldPitchCollection = NULL;
  std::vector<Note> notes; 

  std::shared_ptr<Rhythm> rhythm = mRhythms.at(track).getObject(currentBeat);
  if (nullptr == rhythm)
    rhythm = mRhythms.at("default").getObject(currentBeat);
  if (nullptr == rhythm)
  {
    MelodySequenceIngredientBuilder().build()->apply(*this, "default");
    rhythm = mRhythms.at("default").getObject(currentBeat);
  }

  for (RhythmicNote rhythmicNote : rhythm->getNotes())
  {
    int t = currentBeat + floor(rhythmicNote.getStart());

    std::shared_ptr<PitchSequence> pitches = mPitchSequences.at(track).getObject(t);
    if (nullptr == pitches)
      pitches = mPitchSequences.at("default").getObject(t);
    if (nullptr == pitches)
    {
      MelodySequenceIngredientBuilder().build()->apply(*this, "default");
      pitches = mPitchSequences.at("default").getObject(t);
    }

    /*if (&pitchCollection != oldPitchCollection) compare starting beats of pitch collection stored in Timeline
    {
      oldPitchCollection = &pitchCollection;
      currentPitch = 0;
    }*/
    std::shared_ptr<Scale> scale = mScales.at(track).getObject(t);
    if (nullptr == scale)
      scale = mScales.at("default").getObject(t);
    if (nullptr == scale)
    {
      gDefaultScale->apply(*this, "default");
      scale = mScales.at("default").getObject(t);
    }

    std::shared_ptr<Chord> chord = mChords.at(track).getObject(t);
    if (nullptr == chord)
      chord = mChords.at("default").getObject(t);
    if (nullptr == chord)
    {
      ProgressionIngredientBuilder().build()->apply(*this, "default");
      chord = mChords.at("default").getObject(t);
    }

    std::shared_ptr<Tempo> tempo = mTempos.at(track).getObject(t);
    if (nullptr == tempo)
      tempo = mTempos.at("default").getObject(t);
    if (nullptr == tempo)
    {
      gDefaultTempo->apply(*this, "default");
      tempo = mTempos.at("default").getObject(t);
    }

    std::shared_ptr<Tonic> tonic = mTonics.at(track).getObject(t);
    if (nullptr == tonic)
      tonic = mTonics.at("default").getObject(t);
    if (nullptr == tonic)
    {
      gDefaultTonic->apply(*this, "default");
      tonic = mTonics.at("default").getObject(t);
    }

    std::shared_ptr<int> channel = mChannels.at(track).getObject(t);
    if (nullptr == channel)
      channel = mChannels.at("default").getObject(t);
    if (nullptr == channel)
    {
      ChannelIngredientBuilder().build()->apply(*this, "default");
      channel = mChannels.at("default").getObject(t);
    }

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
