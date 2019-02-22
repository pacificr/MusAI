#pragma once

#include "IIngredient.h"

class SequenceIngredient : public IIngredient
{
  private:
    std::shared_ptr<PitchSequence> mPitchSequence;
    std::shared_ptr<Rhythm> mRhythm;
    std::string mTrack;
  public:
    SequenceIngredient(std::shared_ptr<PitchSequence>, std::shared_ptr<Rhythm>, std::string track = "default");
    void apply(Timeline&) const;
};
