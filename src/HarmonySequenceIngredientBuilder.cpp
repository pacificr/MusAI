#include "../include/HarmonySequenceIngredientBuilder.h"

#include "../include/ChordPitch.h"
#include "../include/SequenceIngredient.h"

std::shared_ptr<IIngredient> HarmonySequenceIngredientBuilder::build()
{
  std::shared_ptr<PitchSequence> pc = std::make_shared<PitchSequence>();
  std::shared_ptr<Rhythm> r = std::make_shared<Rhythm>(16);
  for (int i = 0; i < 4; ++i)
  {
    pc->add(
        std::make_shared<Unison>(
          Unison(std::make_shared<ChordPitch>(0, -1))
          .add(std::make_shared<ChordPitch>(1, -1))
          .add(std::make_shared<ChordPitch>(2, -1))
    ));

    r->add(RhythmicNote(4, 1, 4 * i));
  }
  return std::make_shared<SequenceIngredient>(pc, r);
}

void HarmonySequenceIngredientBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("IngredientBuilder", "HarmonySequenceIngredientBuilder", "Harmony Sequence");
}
