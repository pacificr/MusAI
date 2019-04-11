#pragma once

#include "Chord.h"
#include "IBuilder.h"

#include "Describer.h"

class CustomChordBuilder : public IBuilder<Chord>
{
  public:
    std::vector<int> mDegrees;
    std::shared_ptr<Chord> build();
    static void registerWith(Describer&);
};
