#include "../include/Theme.h"

#include "../include/StructuredGeneratorBuilder.h"

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
