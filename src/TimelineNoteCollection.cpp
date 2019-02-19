#include "../include/TimelineNoteCollection.h"

#include "../include/Rhythm.h"

#include "../include/Logger.h"
#define LOC "timeline"

TimelineNoteCollection::TimelineNoteCollection(std::shared_ptr<Timeline> timeline)
  : mTimeline(timeline){}

std::vector<Note> TimelineNoteCollection::getNotes() const
{
  std::vector<Note> result;
  for (std::string track : mTimeline->getTracks())
  {
    std::vector<Note> notes = mTimeline->getNotes(track);
    result.insert(result.end(), notes.begin(), notes.end());
  }
  return result;
}

double TimelineNoteCollection::getLength() const
{
  return 10;
}
