#pragma once

#include "IGenerator.h"
#include "BuilderSet.h"

class Theme
{
  private:
    BuilderSet<IGenerator> mGenerator;
  public:
    Theme& addGeneratorBuilder(std::shared_ptr<IBuilder<IGenerator>>);
    std::shared_ptr<IGenerator> getGenerator();
};
