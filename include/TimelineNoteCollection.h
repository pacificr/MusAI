#pragma once

#include "INoteCollection.h"
#include "Timeline.h"

class TimelineNoteCollection : public INoteCollection
{
  private:
    std::shared_ptr<Timeline> mTimeline;
  public:
    TimelineNoteCollection(std::shared_ptr<Timeline> timeline);
    std::vector<Note> getNotes() const;
    double getLength() const;
};
