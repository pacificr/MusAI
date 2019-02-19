#pragma once

#include "IProgressionRule.h"

#include "../include/Chord.h"

#include <vector>

class AbsoluteProgressionRule : public IProgressionRule
{
  private:
    std::vector<std::pair<Chord, int>> mChords;
  public:
    void pushChord(Chord&, int); 
    void applyChords(Timeline&, std::string) const;
};
