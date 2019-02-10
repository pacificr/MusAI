#include "../include/Timeline.h"

//Temp

#include "../include/ScalePitch.h"
#include "../include/ChordPitch.h"

std::vector<std::string> Timeline::getTracks()
{
  std::vector<std::string> temp;

  temp.push_back("");
  return temp;
}

Tempo Timeline::getTempo(std::string track, int beat)
{
  return Tempo(80);
}

Tonic Timeline::getTonic(std::string track, int beat)
{
  return Tonic(1);
}

Scale& Timeline::getScale(std::string track, int beat)
{
  std::vector<int> sd;
  sd.push_back(0);
  sd.push_back(2);
  sd.push_back(4);
  sd.push_back(5);
  sd.push_back(7);
  sd.push_back(9);
  sd.push_back(11);
  Scale* scale = new Scale(sd);
  return *scale;
}

Chord& Timeline::getChord(std::string track, int beat)
{
  std::vector<int> cd;
  cd.push_back(0);
  cd.push_back(2);
  cd.push_back(4);
  Chord* chord = new Chord(cd);
  return *chord;
}

PitchCollection& Timeline::getPitchCollection(std::string track, int beat)
{
  PitchCollection* pc = new PitchCollection();

  pc->add(new ScalePitch(2));
  pc->add(new ScalePitch(1));
  pc->add(new ScalePitch(2));
  pc->add(new ScalePitch(-14));
  pc->add(new ScalePitch(-15));
  pc->add(new ScalePitch(6));
  pc->add(new ScalePitch(8));
  pc->add(new ScalePitch(9));


  pc->add(new ChordPitch(-7));  
  pc->add(new ChordPitch(0));  
  pc->add(new ChordPitch(1));  
  pc->add(new ChordPitch(2));

  return *pc;
}

Rhythm& Timeline::getRhythm(std::string track, int beat)
{
  std::vector<RhythmicNote> n;

  for (int i = 0; i < 20; ++i)
  {
    RhythmicNote r;
    r.mStartBeat = i;
    n.push_back(r);
  }
  Rhythm* rhythm = new Rhythm(n, 10);

  return *rhythm;
}
