#include "../include/Theme.h"

#include <time.h>

Theme& Theme::addGeneratorBuilder(std::shared_ptr<IBuilder<IGenerator>> builder)
{
  mGenerator.add(builder);
  return *this;
}

std::shared_ptr<IGenerator> Theme::getGenerator()
{
  srand(time(NULL));
  return mGenerator.get();
}

void Theme::registerWith(Describer& describer)
{
  describer.registerBuilder("Theme", "Theme", "Theme", {
    Describer::builderRequirement("GeneratorBuilder", "generator", "Generator"),
    Describer::builderRequirement("GlobalTempo", "tempo", "Tempo"),
    Describer::builderRequirement("GlobalTonic", "tonic", "Tonic"),
    Describer::builderRequirement("GlobalScale", "scale", "Scale") 
  });
}
