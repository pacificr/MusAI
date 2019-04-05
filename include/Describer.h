#pragma once

#include <json.hpp>

class Describer
{
  private:
    nlohmann::json description;
  public:

    const static std::string SUB_ATTRIBUTE;

    void registerDefaults();
    void registerBuilder(std::string builds, std::string identifier, std::string display, std::vector<nlohmann::json> requirements);
    static nlohmann::json intRequirement(std::string attribute, std::string display, int defaultValue);
    static nlohmann::json mapRequirement(std::string attribute, std::string display, nlohmann::json requirement, bool defaultElement = true);
    static nlohmann::json choiceRequirement(std::string attribute, std::string display, std::vector<std::string> choices);
    static nlohmann::json arrayRequirement(std::string attribute, std::string display, nlohmann::json requirement);
    static nlohmann::json builderRequirement(std::string type, std::string attribute, std::string display);
    std::string getDescription() const;
};
