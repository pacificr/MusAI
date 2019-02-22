#include "../include/ProgressionIngredientBuilder.h"

#include "../include/ProgressionIngredient.h"

std::shared_ptr<IIngredient> ProgressionIngredientBuilder::build()
{
  auto progressionIngredient = std::make_shared<ProgressionIngredient>();

  for (int i = 0; i < 4; ++i)
  {
    std::vector<int> cd;
    int base = rand() % 14 - 7;
    cd.push_back(base);
    cd.push_back(base + 2);
    cd.push_back(base + 4);
    progressionIngredient->pushChord(std::make_shared<Chord>(cd), 4);
  }

  return progressionIngredient;
}
