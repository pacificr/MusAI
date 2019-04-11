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
#include "../include/ChannelIngredientBuilder.h"
#include "../include/TonicIngredientBuilder.h"
#include "../include/BPMTempoIngredientBuilder.h"
#include "../include/RandomTriadChordPoolBuilder.h"
#include "../include/CustomChordPoolBuilder.h"
#include "../include/CustomChordBuilder.h"
#include "../include/ChordBuilder.h"

using json = nlohmann::json;

const std::string Describer::SUB_ATTRIBUTE = "sub-attribute";

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
  ChannelIngredientBuilder::registerWith(*this);
  TonicIngredientBuilder::registerWith(*this);
  BPMTempoIngredientBuilder::registerWith(*this);
  RandomTriadChordPoolBuilder::registerWith(*this);
  CustomChordPoolBuilder::registerWith(*this);
  CustomChordBuilder::registerWith(*this);
  ChordBuilder::registerWith(*this);
}

void Describer::registerBuilder(std::string builds, std::string identifier, std::string display, std::vector<json> requirements)
{
  auto const builderType = description.find(builds);
  if (builderType == description.end())
  {
    description[builds] = json::object();
  }
  description[builds][identifier] = json::object();
  description[builds][identifier]["display"] = display;
  description[builds][identifier]["requirements"] = requirements;
}

json Describer::intRequirement(std::string attribute, std::string display, int defaultValue)
{
  return {
    { "type", "int" },
    { "attribute", attribute },
    { "display", display },
    { "default", defaultValue }
  };
}

json Describer::mapRequirement(std::string attribute, std::string display, json requirement, bool defaultElement)
{
  return {
      { "type", "map" },
      { "attribute", attribute },
      { "display", display },
      { "defaultElement", defaultElement },
      { "requirement", requirement}
  };
}

json Describer::choiceRequirement(std::string attribute, std::string display, std::vector<std::string> choices)
{
  return {
    { "type", "choice" },
    { "attribute", attribute },
    { "display", display },
    { "choices", choices }
  };
}

json Describer::arrayRequirement(std::string attribute, std::string display, json requirement)
{
  return {
    { "type", "array" },
    { "attribute", attribute },
    { "display", display },
    { "requirement", requirement}
  };
}

json Describer::builderRequirement(std::string type, std::string attribute, std::string display)
{
  return {
    { "type", type },
    { "attribute", attribute },
    { "display", display }
  };
}

std::string Describer::getDescription() const
{
  return description.dump();
}
