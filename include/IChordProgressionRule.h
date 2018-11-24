#pragma once

#include "IRule.h"

#include <vector>

class IChordProgressionRule : public IRule
{
public:
  virtual ~IChordProgressionRule() = default;
  virtual std::vector<std::vector<int>> getChords(RuleEnvironment&) = 0;
};