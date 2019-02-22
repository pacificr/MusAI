#include "../include/SequenceIngredient.h"

SequenceIngredient::SequenceIngredient(std::shared_ptr<PitchCollection> pc, std::shared_ptr<Rhythm> r, std::string track)
  : mPitchCollection(pc), mRhythm(r), mTrack(track){}

void SequenceIngredient::apply(Timeline& timeline) const
{
  timeline.add(mPitchCollection, mTrack);
  timeline.add(mRhythm, mTrack);
}
