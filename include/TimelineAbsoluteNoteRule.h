#pragma once

#include "IAbsoluteNoteRule.h"
#include "Timeline.h"

class TimelineAbsoluteNoteRule : public IAbsoluteNoteRule
{
  private:
    Timeline* mTimeline;
  public:
    TimelineAbsoluteNoteRule(Timeline* timeline);
    void describe(RuleEnvironment&);
    std::vector<AbsoluteNote> getAbsoluteNotes(RuleEnvironment&);
    double getLength(RuleEnvironment&);
};
