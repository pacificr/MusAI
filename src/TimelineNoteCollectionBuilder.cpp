#include "../include/TimelineNoteCollectionBuilder.h"

#include "../include/TimelineNoteCollection.h"
#include "../include/ProgressionIngredientBuilder.h"
#include "../include/MelodySequenceIngredientBuilder.h"
#include "../include/HarmonySequenceIngredientBuilder.h"

TimelineNoteCollectionBuilder::TimelineNoteCollectionBuilder()
{
  mProgression.add(std::make_shared<ProgressionIngredientBuilder>());
  mMelody.add(std::make_shared<MelodySequenceIngredientBuilder>());
  mHarmony.add(std::make_shared<HarmonySequenceIngredientBuilder>());
}

std::shared_ptr<INoteCollection> TimelineNoteCollectionBuilder::build()
{  
  std::vector<int> sd;
  sd.push_back(0);
  sd.push_back(2);
  sd.push_back(4);
  sd.push_back(5);
  sd.push_back(7);
  sd.push_back(9);
  sd.push_back(11);
  std::shared_ptr<Scale> scale = std::make_shared<Scale>(sd);
 
  std::shared_ptr<Timeline> timeline = std::make_shared<Timeline>(16);
  timeline->addTrack("melody");
  timeline->addTrack("harmony");
  timeline->add(std::make_shared<Tempo>(Tempo(80)));
  timeline->add(std::make_shared<Tonic>(Tonic(0)));
  timeline->add(scale);

  mProgression.get()->apply(*timeline);
  mMelody.get()->apply(*timeline);
  mHarmony.get()->apply(*timeline);

  return std::make_shared<TimelineNoteCollection>(timeline);
}
