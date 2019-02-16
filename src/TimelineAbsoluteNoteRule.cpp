#include "../include/TimelineAbsoluteNoteRule.h"

#include "../include/Rhythm.h"

#include "../include/Logger.h"
#define LOC "timeline"

TimelineAbsoluteNoteRule::TimelineAbsoluteNoteRule(Timeline* timeline)
  : mTimeline(timeline){}

void TimelineAbsoluteNoteRule::describe(RuleEnvironment& ruleEnvironment){}

std::vector<AbsoluteNote> TimelineAbsoluteNoteRule::getAbsoluteNotes(RuleEnvironment& ruleEnvironment)
{
  std::vector<AbsoluteNote> result;
  for (std::string track : mTimeline->getTracks())
  {
    std::vector<AbsoluteNote> notes = mTimeline->getNotes(track);
    result.insert(result.end(), notes.begin(), notes.end());
  }
  return result;
}

double TimelineAbsoluteNoteRule::getLength(RuleEnvironment& ruleEnvironment)
{
  return 10;
}
