#include "../include/TimelineNoteCollectionBuilder.h"

#include "../include/TimelineNoteCollection.h"
#include "../include/ProgressionIngredientBuilder.h"
#include "../include/MelodySequenceIngredientBuilder.h"
#include "../include/HarmonySequenceIngredientBuilder.h"

void TimelineNoteCollectionBuilder::addIngredientBuilderSet(std::string track, std::shared_ptr<BuilderSet<IIngredient>> ingredientBuilderSet)
{
  mIngredients.insert(std::pair<std::string, std::shared_ptr<BuilderSet<IIngredient>>>(track, ingredientBuilderSet));
}

std::shared_ptr<INoteCollection> TimelineNoteCollectionBuilder::build()
{
  std::shared_ptr<Timeline> timeline = std::make_shared<Timeline>(16);
  for (auto trackIngredient : mIngredients)
  {
    timeline->addTrack(trackIngredient.first);
    trackIngredient.second->get()->apply(*timeline, trackIngredient.first);
  }

  std::vector<int> sd;
  sd.push_back(0);
  sd.push_back(2);
  sd.push_back(4);
  sd.push_back(5);
  sd.push_back(7);
  sd.push_back(9);
  sd.push_back(11);
  std::shared_ptr<Scale> scale = std::make_shared<Scale>(sd);
 
  timeline->add(std::make_shared<Tempo>(Tempo(80)));
  timeline->add(std::make_shared<Tonic>(Tonic(0)));
  timeline->add(scale);

  return std::make_shared<TimelineNoteCollection>(timeline);
}
