#pragma once

template <typename T> class TimelineBucket
{
  private:
    T* mObject;
    int mBegin;
    int mEnd;
  public:
    TimelineBucket(T* object, int begin, int end)
      : mObject(object), mBegin(begin), mEnd(end) {}

    bool matches(int beat)
    {
      return mBegin == -1 || mEnd == -1 || (mBegin <= beat && beat < mEnd);
    }

    bool noTime()
    {
      return mBegin == -1 || mEnd == -1;
    }

    T* getObject()
    {
      return mObject;
    }
};
