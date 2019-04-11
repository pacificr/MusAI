#include "../include/CustomChordPoolBuilder.h"

void CustomChordPoolBuilder::addChord(std::shared_ptr<BuilderSet<Chord>> chord)
{
  mChords.push_back(chord);
}

std::shared_ptr<ChordPool> CustomChordPoolBuilder::build()
{
  std::shared_ptr<ChordPool> cp = std::make_shared<ChordPool>();
  for (auto chord : mChords)
  {
    cp->addChord(chord->get());
  }
  return cp;
}

void CustomChordPoolBuilder::registerWith(Describer& describer)
{
  describer.registerBuilder("ChordPoolBuilder", "CustomChordPoolBuilder", "Custom", {
    Describer::arrayRequirement("chords", "Chords",
      Describer::builderRequirement("ChordBuilder", "chordBuilder", "Chord")
    )
  });
}
