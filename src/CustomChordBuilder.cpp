#include "../include/CustomChordBuilder.h"

static const std::string SCALE = "Scale Degrees";
static const std::string RAW = "Half Steps Above Root";

static const std::string YES = "Yes";
static const std::string NO = "No";

std::shared_ptr<Chord> CustomChordBuilder::build()
{
  int start = 0;
  if (mRandomStartingDegree)
    start = rand() % 14 - 7;
  return std::make_shared<Chord>(mDegrees, mUseScale, start);
}

void CustomChordBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("ChordBuilder", "CustomChordBuilder", "Custom", {
    /*Describer::choiceRequirement("randomStartingDegree", "Start on Random Scale Degree", {
      NO,
      YES
    }),*/
    Describer::choiceRequirement("degreeType", "Degrees Are", {
      SCALE,
      RAW
    }),
    Describer::arrayRequirement("degrees", "Degrees",
        Describer::intRequirement("degree", "Degree", 0)
      )
  });
}
