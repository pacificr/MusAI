#pragma once

#include "ChordPool.h"
#include "IBuilder.h"

#include "Describer.h"
#include "BuilderSet.h"

class CustomChordPoolBuilder : public IBuilder<ChordPool>
{
  private:
    std::vector<std::shared_ptr<BuilderSet<Chord>>> mChords;
  public:
    void addChord(std::shared_ptr<BuilderSet<Chord>>);
    std::shared_ptr<ChordPool> build();
    static void registerWith(Describer&);
};
