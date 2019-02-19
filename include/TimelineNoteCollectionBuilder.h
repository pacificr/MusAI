#pragma once

#include "IBuilder.h"

#include "TimelineNoteCollection.h"

class TimelineNoteCollectionBuilder : public IBuilder<INoteCollection>
{
  public:
    std::shared_ptr<INoteCollection> build();
};
