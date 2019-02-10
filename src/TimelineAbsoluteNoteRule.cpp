#include "../include/TimelineAbsoluteNoteRule.h"

#include "../include/Rhythm.h"

#include "../include/Logger.h"
#define LOC "timeline"

TimelineAbsoluteNoteRule::TimelineAbsoluteNoteRule(Timeline* timeline)
  : mTimeline(timeline){}

void TimelineAbsoluteNoteRule::describe(RuleEnvironment& ruleEnvironment){}

std::vector<AbsoluteNote> TimelineAbsoluteNoteRule::getAbsoluteNotes(RuleEnvironment& ruleEnvironment)
{
  Logger& logger = Logger::instance();
  int currentBeat = 0;
  int currentPitch = 0;
  //PitchCollection* oldPitchCollection = NULL;
  std::vector<AbsoluteNote> notes;
  for (std::string track : mTimeline->getTracks())
  { 
    for (RhythmicNote rhythmicNote : mTimeline->getRhythm(track, currentBeat).getNotes())
    {
      PitchCollection& pitchCollection = mTimeline->getPitchCollection(track, currentBeat + rhythmicNote.mStartBeat);
/*      if (&pitchCollection != oldPitchCollection) compare starting beats of pitch collection stored in Timeline
      {
        oldPitchCollection = &pitchCollection;
        currentPitch = 0;
      }*/

      Scale& scale = mTimeline->getScale(track, currentBeat + rhythmicNote.mStartBeat);
      Chord& chord = mTimeline->getChord(track, currentBeat + rhythmicNote.mStartBeat);
      Tempo tempo = mTimeline->getTempo(track, currentBeat + rhythmicNote.mStartBeat);
      Tonic tonic = mTimeline->getTonic(track, currentBeat + rhythmicNote.mStartBeat); 

      AbsoluteNote note(
          tonic.getCenterPitch() + pitchCollection.getPitch(currentPitch).resolve(scale, chord),
          tempo.applyTempo(
            double(currentBeat)
            + double(rhythmicNote.mStartBeat)
            + (double(rhythmicNote.mStartValue) / double(rhythmicNote.mStartSubdivision))
          ),
          tempo.applyTempo(double(rhythmicNote.mValue) / double(rhythmicNote.mSubdivision))
      );

      logger.log(LOC, "adding note on track " + track + " " + std::to_string(note.mKey)
          + " " + std::to_string(note.mTime)
          + " " + std::to_string(note.mDuration)
          + " " + std::to_string(note.mVelocity)
      );
      notes.push_back(note);

      ++currentPitch;
    }
  }

  return notes;
}

double TimelineAbsoluteNoteRule::getLength(RuleEnvironment& ruleEnvironment)
{
  return 10;
}
