#include "../include/Theme.h"

#include "../include/StructuredGeneratorBuilder.h"

#include <time.h>

Theme::Theme()
{
  mGenerator.add(std::make_shared<StructuredGeneratorBuilder>());
}

std::shared_ptr<IGenerator> Theme::getGenerator()
{
  srand(time(NULL));
  return mGenerator.get();
}
