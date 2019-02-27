#include "../include/ThemeFactory.h"

#include "../include/StructuredGeneratorBuilder.h"
#include "../include/TimelineNoteCollectionBuilder.h"

#include <json.hpp>

#include "../include/Logger.h"
#define LOC "json"

namespace MusAI
{
  using json = nlohmann::json;

  std::shared_ptr<IBuilder<INoteCollection>> getNoteCollectionBuilder(const json& j)
  {
    auto const noteCollectionType = j.find("builder");
    if ("TimelineNoteCollectionBuilder" == *noteCollectionType)
    {
      auto timelineNoteCollectionBuilder = std::make_shared<TimelineNoteCollectionBuilder>();
      return timelineNoteCollectionBuilder;
    }

    Logger::instance().log(LOC, "NoteCollection fail");
    return nullptr;
  }

  std::shared_ptr<IBuilder<IGenerator>> getGeneratorBuilder(const json& j)
  {
    Logger& logger = Logger::instance();
    auto const generatorType = j.find("builder");
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
    Logger& logger = Logger::instance();

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
