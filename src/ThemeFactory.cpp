#include "../include/ThemeFactory.h"

#include "../include/StructuredGeneratorBuilder.h"
#include "../include/TimelineNoteCollectionBuilder.h"
#include "../include/MelodySequenceIngredientBuilder.h"
#include "../include/HarmonySequenceIngredientBuilder.h"
#include "../include/ProgressionIngredientBuilder.h"
#include "../include/ScaleIngredientBuilder.h"
#include "../include/CustomScaleIngredientBuilder.h"
#include "../include/ArpeggioSequenceIngredientBuilder.h"
#include "../include/ChannelIngredientBuilder.h"
#include "../include/TonicIngredientBuilder.h"
#include "../include/BPMTempoIngredientBuilder.h"

#include <json.hpp>

#include "../include/Logger.h"
#define LOC "factory"

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
    else if ("ScaleIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<ScaleIngredientBuilder>();
      
      auto const scale = j.find("scale");
      if (scale != j.end())
        builder->mScaleTitle = *scale;

      return builder;
    }
    else if ("CustomScaleIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<CustomScaleIngredientBuilder>();

      auto const degreeArray = j.find("degrees");
      if (degreeArray != j.end())
        for (auto const& degree : *degreeArray)
          builder->mDegrees.push_back(degree);

      return builder;
    }
    else if("ArpeggioSequenceIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<ArpeggioSequenceIngredientBuilder>();

      auto const length = j.find("length");
      if (length != j.end())
        builder->mLength = *length;

      auto const numNotes = j.find("numNotes");
      if (numNotes != j.end())
        builder->mNumNotes = *numNotes;

      auto const numBeats = j.find("numBeats");
      if (numBeats != j.end())
        builder->mNumBeats = *numBeats;

      auto const octave = j.find("octave");
      if (octave != j.end())
        builder->mOctave = *octave;

      return builder;
    }
    else if ("ChannelIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<ChannelIngredientBuilder>();

      auto const channel = j.find("channel");
      if (channel != j.end())
        builder->mChannel = *channel;

      return builder;
    }
    else if ("TonicIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<TonicIngredientBuilder>();

      auto const tonic = j.find("tonic");
      if (tonic != j.end())
        builder->mTonicTitle = *tonic;

      auto const octave = j.find("octave");
      if (octave != j.end())
        builder->mOctave = *octave;

      return builder;
    }
    else if ("BPMTempoIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<BPMTempoIngredientBuilder>();

      auto const minBPM = j.find("minBPM");
      if (minBPM != j.end())
        builder->mMinBPM = *minBPM;

      auto const maxBPM = j.find("maxBPM");
      if (maxBPM != j.end())
        builder->mMaxBPM = *maxBPM;

      return builder;
    }

    logger.log(LOC, "Ingredient ================ FAIL");
    return nullptr;
  }

  std::shared_ptr<BuilderSet<IIngredient>> getIngredientBuilderSet(const json& j)
  {
    std::shared_ptr<BuilderSet<IIngredient>> builderSet = std::make_shared<BuilderSet<IIngredient>>();
    for (auto const& builder : j)
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
          for (auto const& builderArray : track.value())
            timelineNoteCollectionBuilder->addIngredientBuilderSet(track.key(), getIngredientBuilderSet(builderArray));

      auto const length = j.find("length");
      if (length != j.end())
        timelineNoteCollectionBuilder->mLength = *length;

      return timelineNoteCollectionBuilder;
    }

    logger.log(LOC, "NoteCollection ====================== FAIL");
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

    logger.log(LOC, "Generator ========================== FAIL");
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
