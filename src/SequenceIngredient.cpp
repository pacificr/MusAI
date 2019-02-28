#include "../include/SequenceIngredient.h"

SequenceIngredient::SequenceIngredient(std::shared_ptr<PitchSequence> pc, std::shared_ptr<Rhythm> r)
  : mPitchSequence(pc), mRhythm(r){}

void SequenceIngredient::apply(Timeline& timeline, std::string track)
{
  timeline.add(mPitchSequence, track);
  timeline.add(mRhythm, track);
}
