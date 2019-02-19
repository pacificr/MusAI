#pragma once

#include "IGenerator.h"
#include "StructureControl.h"

class StructuredGenerator : public IGenerator
{
  private:
    std::vector<std::shared_ptr<StructureControl>> mControls;
    std::shared_ptr<StructureControl> mStructureControl;
    double mStructureStart = 0;
    double mTimeElapsed = 0;
  public:
    StructuredGenerator(std::vector<std::shared_ptr<StructureControl>>&);
    MIDIStream getNext(double time);
    //MIDIStream getNext(int beats);
};
