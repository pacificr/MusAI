#pragma once

#include "IBuilder.h"

#include <set>
#include <memory>

template <typename T> class BuilderSet
{
  private:
    std::set<std::shared_ptr<IBuilder<T>>> mSet;
    std::shared_ptr<T> mObject = nullptr;
  public:
    void add(std::shared_ptr<IBuilder<T>> builder)
    {
      mSet.insert(builder);
    }
    void randomize()
    {
      unsigned int choice = rand() % mSet.size();
      auto objectIt = mSet.begin();
      std::advance(objectIt, choice);
      mObject = (*objectIt)->build();
    }
    std::shared_ptr<T> get()
    {
      if (mObject == nullptr)
        randomize();
      return mObject;
    }
    unsigned int size()
    {
      return mSet.size();
    }
};
