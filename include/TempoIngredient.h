#pragma once

#include "IIngredient.h"

class TempoIngredient : public IIngredient
{
private:
  int mTempo;
public:
  TempoIngredient(int tempo) : mTempo(tempo) {};
  void apply(Timeline&, std::string);
};
