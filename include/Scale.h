#pragma once

#include <vector>

class Scale
{
  private:
    std::vector<int> mScaleDegrees;
  public:
    Scale(std::vector<int>);
    int resolveDegree(int) const;
    unsigned int size() const;
};
