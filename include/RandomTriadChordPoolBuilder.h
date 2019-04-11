#pragma once

#include "ChordPool.h"
#include "IBuilder.h"

#include "Describer.h"

class RandomTriadChordPoolBuilder : public IBuilder<ChordPool>
{
  public:
    std::shared_ptr<ChordPool> build();
    static void registerWith(Describer&);
};
