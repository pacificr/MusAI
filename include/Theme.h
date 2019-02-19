#pragma once

#include "IGenerator.h"
#include "BuilderSet.h"

class Theme
{
  private:
    BuilderSet<IGenerator> mGenerator;
  public:
    Theme();
    std::shared_ptr<IGenerator> getGenerator();
};
