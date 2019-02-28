#pragma once

#include "IIngredient.h"

#include "../include/Chord.h"

#include <vector>

class ProgressionIngredient : public IIngredient
{
  private:
    std::vector<std::pair<std::shared_ptr<Chord>, int>> mChords;
  public:
    void pushChord(std::shared_ptr<Chord>, int); 
    void apply(Timeline&, std::string);
};
