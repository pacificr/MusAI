#pragma once

#include <memory>

template <typename T> class TimelineBucket
{
  private:
    std::shared_ptr<T> mObject;
    int mBegin;
    int mEnd;
  public:
    TimelineBucket(std::shared_ptr<T> object, int begin, int end)
      : mObject(object), mBegin(begin), mEnd(end) {}

    bool matches(int beat) const
    {
      return mBegin == -1 || mEnd == -1 || (mBegin <= beat && beat < mEnd);
    }

    bool noTime() const
    {
      return mBegin == -1 || mEnd == -1;
    }

    std::shared_ptr<T> getObject() const
    {
      return mObject;
    }
};
