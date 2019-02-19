#pragma once

#include <memory>

template <typename T> class IBuilder
{
  public:
    virtual ~IBuilder() = default;
    virtual std::shared_ptr<T> build() = 0;
};
