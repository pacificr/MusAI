#pragma once

#include <json.hpp>

class Describer
{
  private:
    nlohmann::json description;
  public:
    void registerDefaults();
    void registerBuilder(std::string builds, std::string identifier, std::string display);
    void registerIntRequirement(std::string builds, std::string identifier, std::string attribute, std::string display, int defaultValue);
    void registerMapRequirement(std::string builds, std::string identifier, std::string attribute, std::string display, std::string type, std::string typeDisplay, bool defaultElement = true);
    void registerChoiceRequirement(std::string builds, std::string identifier, std::string attribute, std::string display, std::vector<std::string> choices);
    void registerBuilderRequirement(std::string builds, std::string identifier, std::string type, std::string attribute, std::string display);
    std::string getDescription() const;
};
