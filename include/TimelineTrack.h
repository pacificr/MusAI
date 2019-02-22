#pragma once

#include "TimelineBucket.h"

#include <vector>

template <typename T> class TimelineTrack
{
  private:
    std::vector<TimelineBucket<T>> mBuckets;
  public:
    void add(TimelineBucket<T> bucket)
    {
      if (bucket.noTime())
        mBuckets.insert(mBuckets.begin(), bucket);
      else
        mBuckets.push_back(bucket);
    }

    std::shared_ptr<T> getObject(int beat = 0) const
    {
      std::shared_ptr<T> result = nullptr;

      for (TimelineBucket<T> bucket : mBuckets)
        if (bucket.matches(beat))
          result = bucket.getObject();

      return result;
    }
};
