#include "../include/ThemeFactory.h"

#include "../include/StructuredGeneratorBuilder.h"
#include "../include/TimelineNoteCollectionBuilder.h"
#include "../include/MelodySequenceIngredientBuilder.h"
#include "../include/HarmonySequenceIngredientBuilder.h"
#include "../include/ProgressionIngredientBuilder.h"

#include <json.hpp>

#include "../include/Logger.h"
#define LOC "json"

namespace MusAI
{
  using json = nlohmann::json;
  Logger& logger = Logger::instance();

  std::shared_ptr<IBuilder<IIngredient>> getIngredientBuilder(const json& j)
  {
    auto const ingredientBuilderType = j.find("type");
    logger.log(LOC, *ingredientBuilderType);
    if ("MelodySequenceIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<MelodySequenceIngredientBuilder>();
      return builder;
    }
    else if ("HarmonySequenceIngredientBuilder"== *ingredientBuilderType)
    {
      auto builder = std::make_shared<HarmonySequenceIngredientBuilder>();
      return builder;
    }
    else if ("ProgressionIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<ProgressionIngredientBuilder>();
      return builder;
    }

    logger.log(LOC, "Ingredient fail");
    return nullptr;
  }

  std::shared_ptr<BuilderSet<IIngredient>> getIngredientBuilderSet(const json& j)
  {
    std::shared_ptr<BuilderSet<IIngredient>> builderSet = std::make_shared<BuilderSet<IIngredient>>();
    for (auto const& builderArray : j)
      for (auto const& builder : builderArray)
        builderSet->add(getIngredientBuilder(builder));
    return builderSet;
  }

  std::shared_ptr<IBuilder<INoteCollection>> getNoteCollectionBuilder(const json& j)
  {
    auto const noteCollectionType = j.find("type");
    logger.log(LOC, *noteCollectionType);
    if ("TimelineNoteCollectionBuilder" == *noteCollectionType)
    {
      auto timelineNoteCollectionBuilder = std::make_shared<TimelineNoteCollectionBuilder>();

      auto const ingredients = j.find("ingredients");
      if (ingredients != j.end())
        for (auto& track : ingredients->items())
          timelineNoteCollectionBuilder->addIngredientBuilderSet(track.key(), getIngredientBuilderSet(track.value()));
      return timelineNoteCollectionBuilder;
    }

    logger.log(LOC, "NoteCollection fail");
    return nullptr;
  }

  std::shared_ptr<IBuilder<IGenerator>> getGeneratorBuilder(const json& j)
  {
    auto const generatorType = j.find("type");
    logger.log(LOC, *generatorType);
    if ("StructuredGeneratorBuilder" == *generatorType)
    {
      auto structuredGeneratorBuilder = std::make_shared<StructuredGeneratorBuilder>();

      auto const minSections = j.find("minSections");
      if (minSections != j.end())
        structuredGeneratorBuilder->mMinSections = *minSections;

      auto const maxSections = j.find("maxSections");
      if (maxSections != j.end())
        structuredGeneratorBuilder->mMaxSections = *maxSections; 

      auto const noteCollectionArray = j.find("noteCollection");

      if (noteCollectionArray == j.end())
        logger.log(LOC, "note collection not found, use default");
      else
        for (auto const& noteCollection : *noteCollectionArray)
          structuredGeneratorBuilder->addNoteCollectionBuilder(getNoteCollectionBuilder(noteCollection));

      return structuredGeneratorBuilder;
    }

    logger.log(LOC, "Generator fail");
    return nullptr;
  }

  std::shared_ptr<Theme> getTheme(std::string json_data)
  {
    json j = json::parse(json_data);
    auto theme = std::make_shared<Theme>();

    auto const generatorArray = j.find("generator");
    if (generatorArray == j.end())
    {
      logger.log(LOC, "generator not found, use default");
    }
    else
    {
      for (auto const& generator : *generatorArray)
        theme->addGeneratorBuilder(getGeneratorBuilder(generator));
    }

    return theme;
  }
}
