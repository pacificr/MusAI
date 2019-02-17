#pragma once

#include "IAbsoluteNoteRule.h"
#include "Timeline.h"

class TimelineAbsoluteNoteRule : public IAbsoluteNoteRule
{
  private:
    std::shared_ptr<Timeline> mTimeline;
  public:
    TimelineAbsoluteNoteRule(std::shared_ptr<Timeline> timeline);
    void describe(RuleEnvironment&);
    std::vector<AbsoluteNote> getAbsoluteNotes(RuleEnvironment&);
    double getLength(RuleEnvironment&);
};
