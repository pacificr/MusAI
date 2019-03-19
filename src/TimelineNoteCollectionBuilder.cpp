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
  std::shared_ptr<Timeline> timeline = std::make_shared<Timeline>();
  for (auto trackIngredient : mIngredients)
  {
    timeline->addTrack(trackIngredient.first);
    trackIngredient.second->randomize();
    trackIngredient.second->get()->apply(*timeline, trackIngredient.first);
  }

  timeline->add(std::make_shared<Tempo>(Tempo(80)));
  timeline->add(std::make_shared<Tonic>(Tonic(0)));

  return std::make_shared<TimelineNoteCollection>(timeline);
}

void TimelineNoteCollectionBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("NoteCollectionBuilder", "TimelineNoteCollectionBuilder", "Timeline");
  describer.registerMapRequirement("NoteCollectionBuilder", "TimelineNoteCollectionBuilder", "ingredients", "Tracks", "IngredientBuilder", "Ingredient");
}
