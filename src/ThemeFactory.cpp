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
#include "../include/RandomTriadChordPoolBuilder.h"
#include "../include/CustomChordPoolBuilder.h"
#include "../include/CustomChordBuilder.h"
#include "../include/ChordBuilder.h"

#include <json.hpp>

#include "../include/Logger.h"
#define LOC "factory"

namespace MusAI
{
  using json = nlohmann::json;
  Logger& logger = Logger::instance();

  std::shared_ptr<IBuilder<Chord>> getChordBuilder(const json &j)
  {
    auto const chordBuilderType = j.find("type");
    logger.log(LOC, *chordBuilderType);
    if ("CustomChordBuilder" == *chordBuilderType)
    {
      auto chord = std::make_shared<CustomChordBuilder>();

      auto const degreeArray = j.find("degrees");
      if (degreeArray != j.end())
        for (auto const& degree : *degreeArray)
          chord->mDegrees.push_back(degree);

      return chord;
    }
    else if ("ChordBuilder" == *chordBuilderType)
    {
      auto chord = std::make_shared<ChordBuilder>();

      auto const octave = j.find("octave");
      if (octave != j.end())
        chord->mOctave = *octave;

      auto const base = j.find("base");
      if (base != j.end())
        chord->mBase = *base;

      auto const chordTitle = j.find("chordTitle");
      if (chordTitle != j.end())
        chord->mChordTitle = *chordTitle;

      return chord;
    }
    logger.log(LOC, "Chord ================================= FAIL");
    return nullptr;
  }

  std::shared_ptr<IBuilder<ChordPool>> getChordPoolBuilder(const json &j)
  {
    auto const chordPoolBuilderType = j.find("type");
    logger.log(LOC, *chordPoolBuilderType);
    if ("RandomTriadChordPoolBuilder" == *chordPoolBuilderType)
    {
      auto pool = std::make_shared<RandomTriadChordPoolBuilder>();
      return pool;
    }
    else if ("CustomChordPoolBuilder" == *chordPoolBuilderType)
    {
      auto pool = std::make_shared<CustomChordPoolBuilder>();

      auto const chords = j.find("chords");
      if (chords == j.end())
        logger.log(LOC, "chord not found, error");
      else
        for (auto const& builderSet : *chords)
        {
          std::shared_ptr<BuilderSet<Chord>> bs = std::make_shared<BuilderSet<Chord>>();
          for (auto const& chord : builderSet)
            bs->add(getChordBuilder(chord));
          pool->addChord(bs);
        }

      return pool;
    }

    logger.log(LOC, "ChordPool ============================ FAIL");
    return nullptr;
  }

  std::shared_ptr<IBuilder<IIngredient>> getIngredientBuilder(const json& j, unsigned int numBeats)
  {
    auto const ingredientBuilderType = j.find("type");
    logger.log(LOC, *ingredientBuilderType);
    if ("MelodySequenceIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<MelodySequenceIngredientBuilder>();

      builder->mNumBeats = numBeats;

      return builder;
    }
    else if ("HarmonySequenceIngredientBuilder"== *ingredientBuilderType)
    {
      auto builder = std::make_shared<HarmonySequenceIngredientBuilder>();

      builder->mNumBeats = numBeats;

      return builder;
    }
    else if ("ProgressionIngredientBuilder" == *ingredientBuilderType)
    {
      auto builder = std::make_shared<ProgressionIngredientBuilder>();

      auto const chordLength = j.find("chordLength");
      if (chordLength != j.end())
        builder->mChordLength = *chordLength;

      auto const order = j.find("order");
      if (order != j.end())
        builder->mInOrder = *order == "In Order";

      auto const chordPoolArray = j.find("chordPool");
      if (chordPoolArray == j.end())
        logger.log(LOC, "chord pool not found, use default");
      else
        for (auto const& chordPool : *chordPoolArray)
          builder->addChordPool(getChordPoolBuilder(chordPool));

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

      builder->mNumBeats = numBeats;

      auto const numNotes = j.find("numNotes");
      if (numNotes != j.end())
        builder->mNumNotes = *numNotes;

      auto const overBeats = j.find("overBeats");
      if (overBeats != j.end())
        builder->mOverBeats = *overBeats;

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

  std::shared_ptr<BuilderSet<IIngredient>> getIngredientBuilderSet(const json& j, unsigned int numBeats)
  {
    std::shared_ptr<BuilderSet<IIngredient>> builderSet = std::make_shared<BuilderSet<IIngredient>>();
    for (auto const& builder : j)
      builderSet->add(getIngredientBuilder(builder, numBeats));
    return builderSet;
  }

  std::shared_ptr<IBuilder<INoteCollection>> getNoteCollectionBuilder(const json& j)
  {
    auto const noteCollectionType = j.find("type");
    logger.log(LOC, *noteCollectionType);
    if ("TimelineNoteCollectionBuilder" == *noteCollectionType)
    {
      auto timelineNoteCollectionBuilder = std::make_shared<TimelineNoteCollectionBuilder>();

      auto const length = j.find("length");
      if (length != j.end())
        timelineNoteCollectionBuilder->mLength = *length;

      auto const ingredients = j.find("ingredients");
      if (ingredients != j.end())
        for (auto& track : ingredients->items())
          for (auto const& builderArray : track.value())
            timelineNoteCollectionBuilder->addIngredientBuilderSet(track.key(), getIngredientBuilderSet(builderArray, *length));

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
