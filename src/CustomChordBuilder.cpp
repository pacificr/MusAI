#include "../include/CustomChordBuilder.h"

std::shared_ptr<Chord> CustomChordBuilder::build()
{
  return std::make_shared<Chord>(mDegrees);
}

void CustomChordBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("ChordBuilder", "CustomChordBuilder", "Custom", {
    Describer::arrayRequirement("degrees", "Degrees",
        Describer::intRequirement("degree", "Degree", 0)
      )
  });
}
