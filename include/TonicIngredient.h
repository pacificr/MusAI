#pragma once

#include "IIngredient.h"

class TonicIngredient : public IIngredient
{
private:
  int mTonic;
  int mOctave;
public:
  TonicIngredient(int tonic, int octave)
    : mTonic(tonic), mOctave(octave) {};
  void apply (Timeline&, std::string);
};
