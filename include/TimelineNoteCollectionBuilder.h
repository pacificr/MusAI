#pragma once

#include "IBuilder.h"
#include "INoteCollection.h"

#include "IIngredient.h"
#include "BuilderSet.h"

#include <map>

class TimelineNoteCollectionBuilder : public IBuilder<INoteCollection>
{
  private:
    std::multimap<std::string, std::shared_ptr<BuilderSet<IIngredient>>> mIngredients;
  public:
    void addIngredientBuilderSet(std::string, std::shared_ptr<BuilderSet<IIngredient>>);
    std::shared_ptr<INoteCollection> build();
};
