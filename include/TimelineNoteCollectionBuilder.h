#pragma once

#include "IBuilder.h"
#include "INoteCollection.h"

#include "Describer.h"
#include "IIngredient.h"
#include "BuilderSet.h"

#include <map>

class TimelineNoteCollectionBuilder : public IBuilder<INoteCollection>
{
  private:
    std::multimap<std::string, std::shared_ptr<BuilderSet<IIngredient>>> mIngredients;
  public:
    int mLength;
    bool mUseSlowestTempo = true;
    void addIngredientBuilderSet(std::string, std::shared_ptr<BuilderSet<IIngredient>>);
    std::shared_ptr<INoteCollection> build();
    static void registerWith(Describer&);
};
