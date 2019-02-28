#pragma once

#include "IIngredient.h"

class SequenceIngredient : public IIngredient
{
  private:
    std::shared_ptr<PitchSequence> mPitchSequence;
    std::shared_ptr<Rhythm> mRhythm;
  public:
    SequenceIngredient(std::shared_ptr<PitchSequence>, std::shared_ptr<Rhythm>);
    void apply(Timeline&, std::string);
};
