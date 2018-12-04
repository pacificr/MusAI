#pragma once

#include "IRule.h"

#include "MIDIStream.h"

class IGenerator : public IRule
{
public:
  virtual ~IGenerator() = default;
  virtual MIDIStream getNext(double time) = 0;
};