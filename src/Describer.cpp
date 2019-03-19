#include "../include/Describer.h"

#include "../include/Theme.h"
#include "../include/StructuredGeneratorBuilder.h"
#include "../include/TimelineNoteCollectionBuilder.h"
#include "../include/ProgressionIngredientBuilder.h"
#include "../include/ScaleIngredientBuilder.h"
#include "../include/CustomScaleIngredientBuilder.h"
#include "../include/MelodySequenceIngredientBuilder.h"
#include "../include/HarmonySequenceIngredientBuilder.h"
#include "../include/ArpeggioSequenceIngredientBuilder.h"

using json = nlohmann::json;

void Describer::registerDefaults()
{
  Theme::registerWith(*this);
  StructuredGeneratorBuilder::registerWith(*this);
  TimelineNoteCollectionBuilder::registerWith(*this);
  ProgressionIngredientBuilder::registerWith(*this);
  ScaleIngredientBuilder::registerWith(*this);
  CustomScaleIngredientBuilder::registerWith(*this);
  MelodySequenceIngredientBuilder::registerWith(*this);
  HarmonySequenceIngredientBuilder::registerWith(*this);
  ArpeggioSequenceIngredientBuilder::registerWith(*this);
}

void Describer::registerBuilder(std::string builds, std::string identifier, std::string display)
{
  auto const builderType = description.find(builds);
  if (builderType == description.end())
  {
    description[builds] = json::object();
  }
  description[builds][identifier] = json::object();
  description[builds][identifier]["display"] = display;
  description[builds][identifier]["requirements"] = json::array();
}

void Describer::registerIntRequirement(std::string builds, std::string identifier, std::string attribute, std::string display, int defaultValue)
{
  description[builds][identifier]["requirements"].push_back({
    { "type", "int" },
    { "attribute", attribute },
    { "display", display },
    { "default", defaultValue }
  });
}

void Describer::registerMapRequirement(std::string builds, std::string identifier, std::string attribute, std::string display, std::string type, std::string typeDisplay, bool defaultElement)
{
  description[builds][identifier]["requirements"].push_back({
      { "type", "map" },
      { "attribute", attribute },
      { "display", display },
      { "defaultElement", defaultElement },
      { "requirement", {
        { "type", type },
        { "display", typeDisplay }
      }}
  });
}

void Describer::registerChoiceRequirement(std::string builds, std::string identifier, std::string attribute, std::string display, std::vector<std::string> choices)
{
  description[builds][identifier]["requirements"].push_back({
    { "type", "choice" },
    { "attribute", attribute },
    { "display", display },
    { "choices", choices }
  });
}

void Describer::registerBuilderRequirement(std::string builds, std::string identifier, std::string type, std::string attribute, std::string display)
{
  description[builds][identifier]["requirements"].push_back({
    { "type", type },
    { "attribute", attribute },
    { "display", display }
  });
}

std::string Describer::getDescription() const
{
  return description.dump();
}
