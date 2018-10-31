#pragma once

#include "MIDIStream.h"

class IGenerator
{
public:
  virtual ~IGenerator() = default;
  virtual MIDIStream getNext(double time) = 0;
};