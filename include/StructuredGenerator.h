#pragma once

#include "RuleEnvironment.h"
#include "IGenerator.h"
#include "StructureControl.h"
#include "Note.h"

class StructuredGenerator : public IGenerator
{
private:
  RuleEnvironment* mRuleEnvironment;
  StructureControl* mStructureControl;
  double mStructureStart = 0;
  double mTimeElapsed = 0;
public:
  StructuredGenerator(RuleEnvironment*, StructureControl*);
  ~StructuredGenerator();
  MIDIStream getNext(double time);
  //MIDIStream getNext(int beats);
};