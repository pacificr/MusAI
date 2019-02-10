
#include "../include/Logger.h"

#include "../include/TestRule.h"
#include "../include/Theme.h"
#include "../include/StructuredGeneratorBuilder.h"
#include "../include/BasicAbsoluteNoteRule.h"
#include "../include/AbsoluteTonicRule.h"
#include "../include/AbsoluteSubdivisionRule.h"
#include "../include/AbsoluteTempoRule.h"
#include "../include/BasicScaleRule.h"
#include "../include/ScaleChordProgressionRule.h"
#include "../include/StepMelodyBuilder.h"
#include "../include/BasicHarmonyRule.h"

#include "../include/ScalePitch.h"
#include "../include/ChordPitch.h"
#include "../include/PitchCollection.h"

#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
  srand(time(NULL));

  Logger& logger = Logger::instance();
  for (int i = 1; i < argc; ++i)
  {
    logger.enable(argv[i]);
  } 

  Theme theme;
  //TestRule test;
  StepMelodyBuilder melodyBuilder;
  BasicHarmonyRule h;
  //StructuredGeneratorRule p;
  StructuredGeneratorBuilder p;
  AbsoluteTonicRule t(72);
  AbsoluteSubdivisionRule s(4);
  AbsoluteTempoRule tt(60);
  BasicScaleRule ss(SCALE::MAJOR);
  ScaleChordProgressionRule c({0, 1, 2, 3});
  theme.addRule(p);
  theme.addRule(melodyBuilder);
  theme.addRule(h);
  theme.addRule(t);
  theme.addRule(s);
  theme.addRule(tt);
  theme.addRule(ss);
  theme.addRule(c);
  IGenerator* generator = theme.getGenerator();

  MIDIStream stream = generator->getNext(16);

  while (stream.hasNext())
  {
    logger.log("test", std::to_string(stream.getNext().mKey));
    stream.getNext();
  }

  delete generator;

  return 0;
}
