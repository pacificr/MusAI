#include "../include/SequenceIngredient.h"

SequenceIngredient::SequenceIngredient(std::shared_ptr<PitchSequence> pc, std::shared_ptr<Rhythm> r, std::string track)
  : mPitchSequence(pc), mRhythm(r), mTrack(track){}

void SequenceIngredient::apply(Timeline& timeline) const
{
  timeline.add(mPitchSequence, mTrack);
  timeline.add(mRhythm, mTrack);
}
