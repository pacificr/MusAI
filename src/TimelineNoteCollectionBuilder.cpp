#include "../include/TimelineNoteCollectionBuilder.h"

#include "../include/ScalePitch.h"
#include "../include/ChordPitch.h"

std::shared_ptr<INoteCollection> TimelineNoteCollectionBuilder::build()
{
  //test
  std::vector<int> sd;
  sd.push_back(0);
  sd.push_back(2);
  sd.push_back(4);
  sd.push_back(5);
  sd.push_back(7);
  sd.push_back(9);
  sd.push_back(11);
  std::shared_ptr<Scale> scale = std::make_shared<Scale>(sd);
  
  std::vector<int> cd;
  cd.push_back(0);
  cd.push_back(2);
  cd.push_back(4);
  std::shared_ptr<Chord> chord = std::make_shared<Chord>(cd);

  std::shared_ptr<PitchCollection> pc = std::make_shared<PitchCollection>();

  pc->add(std::make_shared<ScalePitch>(2));
  pc->add(std::make_shared<ScalePitch>(1));
  pc->add(std::make_shared<ScalePitch>(2));
  pc->add(std::make_shared<ScalePitch>(-14));
  pc->add(std::make_shared<ScalePitch>(-15));
  pc->add(std::make_shared<ScalePitch>(6));
  pc->add(std::make_shared<ScalePitch>(8));
  pc->add(std::make_shared<ScalePitch>(9));


  pc->add(std::make_shared<ChordPitch>(-7));
  pc->add(std::make_shared<ChordPitch>(0));
  pc->add(std::make_shared<ChordPitch>(1));
  pc->add(std::make_shared<ChordPitch>(2));

  std::vector<RhythmicNote> n;

  for (int i = 0; i < 20; ++i)
  {
    RhythmicNote r;
    r.mStartBeat = i;
    n.push_back(r);
  }
  std::shared_ptr<Rhythm> rhythm = std::make_shared<Rhythm>(n, 10);


  std::shared_ptr<Timeline> timeline = std::make_shared<Timeline>();
  timeline->addTrack("test");
  timeline->add(std::make_shared<Tempo>(Tempo(80)), "test");
  timeline->add(std::make_shared<Tonic>(Tonic(1)), "test");
  timeline->add(scale, "test");
  timeline->add(chord, "test");
  timeline->add(pc, "test");
  timeline->add(rhythm, "test");

  return std::make_shared<TimelineNoteCollection>(timeline);
}
