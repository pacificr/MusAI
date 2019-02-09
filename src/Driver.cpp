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

int main()
{
  srand(time(NULL));

  std::vector<IPitch*> pv;


  pv.push_back(new ChordPitch(0));
  pv.push_back(new ChordPitch(1));
  pv.push_back(new ChordPitch(2));
  pv.push_back(new ChordPitch(3));
  pv.push_back(new ChordPitch(4));
  pv.push_back(new ChordPitch(5));
  pv.push_back(new ChordPitch(6));
  pv.push_back(new ChordPitch(-1));
  pv.push_back(new ChordPitch(-2));
  pv.push_back(new ChordPitch(-3));
  pv.push_back(new ChordPitch(-4));
  pv.push_back(new ChordPitch(-5));
  pv.push_back(new ScalePitch(1));
  pv.push_back(new ScalePitch(2));
  pv.push_back(new ScalePitch(3));
  pv.push_back(new ScalePitch(4));
  pv.push_back(new ScalePitch(5));
  pv.push_back(new ScalePitch(6));
  pv.push_back(new ScalePitch(7));
  pv.push_back(new ScalePitch(8));
  pv.push_back(new ScalePitch(-1));
  pv.push_back(new ScalePitch(-2));
  pv.push_back(new ScalePitch(-3));
  pv.push_back(new ScalePitch(-4));
  pv.push_back(new ScalePitch(-5));
  pv.push_back(new ScalePitch(-6));
  pv.push_back(new ScalePitch(-7));
  pv.push_back(new ScalePitch(-8));
  pv.push_back(new ScalePitch(-14));
  pv.push_back(new ScalePitch(-16));
  pv.push_back(new ScalePitch(-17));

  std::vector<int> scaleDegs;

  scaleDegs.push_back(0);
  scaleDegs.push_back(2);
  scaleDegs.push_back(4);
  scaleDegs.push_back(5);
  scaleDegs.push_back(7);
  scaleDegs.push_back(9);
  scaleDegs.push_back(11);

  Scale scale(scaleDegs);

  std::vector<int> chordDegs;

  chordDegs.push_back(0);
  chordDegs.push_back(2);
  chordDegs.push_back(4);

  Chord chord(chordDegs);

  PitchCollection pc(pv);




  for (unsigned int i = 0; i < pv.size(); ++i)
  {
    std::cout << pc.getPitch(i).resolve(scale, chord) << std::endl;
  }

  std::cout << "================" << std::endl;

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
    std::cout << stream.getNext().mKey << std::endl;
    stream.getNext();
  }

  delete generator;

  return 0;
}
