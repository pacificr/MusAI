#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/StructureControl.h"
#include "../include/TimelineAbsoluteNoteRule.h"
//#include "../include/IBuilder.h"

//Temp
#include "../include/ScalePitch.h"
#include "../include/ChordPitch.h"

#include "../include/Logger.h"
#define LOC "structure"

void StructuredGeneratorBuilder::describe(RuleEnvironment &ruleEnvironment)
{
  ruleEnvironment.addBuilds("Generator", this);
}

IRule *StructuredGeneratorBuilder::build(RuleEnvironment &ruleEnvironment)
{
  Logger& logger = Logger::instance();

  if (mMinSections < 1)
    mMinSections = 1;

  mMaxSections = 1;//TEMPORARY
  int numSections = (rand() % (mMaxSections - mMinSections + 1)) + mMinSections;
  int sectionsToBuild = numSections - 1;
  int current = 0;

  logger.log(LOC, "numSections: " + std::to_string(numSections));

  std::vector<StructureControl*> sections;
  sections.resize(numSections);

  std::string id = std::to_string(rand());

  //test
  std::vector<int> sd;
  sd.push_back(0);
  sd.push_back(2);
  sd.push_back(4);
  sd.push_back(5);
  sd.push_back(7);
  sd.push_back(9);
  sd.push_back(11);
  std::shared_ptr<Scale> scale = std::make_shared<Scale>(Scale(sd));
  
  std::vector<int> cd;
  cd.push_back(0);
  cd.push_back(2);
  cd.push_back(4);
  std::shared_ptr<Chord> chord = std::make_shared<Chord>(Chord(cd));

  std::shared_ptr<PitchCollection> pc = std::make_shared<PitchCollection>(PitchCollection());

  pc->add(std::make_shared<ScalePitch>(ScalePitch(2)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(1)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(2)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(-14)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(-15)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(6)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(8)));
  pc->add(std::make_shared<ScalePitch>(ScalePitch(9)));


  pc->add(std::make_shared<ChordPitch>(ChordPitch(-7)));
  pc->add(std::make_shared<ChordPitch>(ChordPitch(0)));
  pc->add(std::make_shared<ChordPitch>(ChordPitch(1)));
  pc->add(std::make_shared<ChordPitch>(ChordPitch(2)));

  std::vector<RhythmicNote> n;

  for (int i = 0; i < 20; ++i)
  {
    RhythmicNote r;
    r.mStartBeat = i;
    n.push_back(r);
  }
  std::shared_ptr<Rhythm> rhythm = std::make_shared<Rhythm>(Rhythm(n, 10));


  std::shared_ptr<Timeline> timeline = std::make_shared<Timeline>(Timeline());
  timeline->addTrack("test");
  timeline->add(std::make_shared<Tempo>(Tempo(80)), "test");
  timeline->add(std::make_shared<Tonic>(Tonic(1)), "test");
  timeline->add(scale, "test");
  timeline->add(chord, "test");
  timeline->add(pc, "test");
  timeline->add(rhythm, "test");

  sections[current] = new StructureControl(std::make_shared<TimelineAbsoluteNoteRule>(TimelineAbsoluteNoteRule(timeline)), id);
  /*sections[current] = new StructureControl(
    new BasicAbsoluteNoteRule(id),
    id
  );
  ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);*/

  if (sectionsToBuild <= 0)
    sections[current]->addControl(sections[current], ruleEnvironment);
  else
  {
    for (int i = 1; i < numSections; ++i)
      sections[i] = NULL;

    while(sectionsToBuild > 0 || current != 0)
    {
      int selection = rand() % numSections;
      if(sections[selection] == NULL)
      {
        id = std::to_string(rand());
        sections[current] = new StructureControl(std::make_shared<TimelineAbsoluteNoteRule>(TimelineAbsoluteNoteRule(timeline)), id);
        /*sections[selection] = new StructureControl(
          new BasicAbsoluteNoteRule(id),
          id
        );
        ruleEnvironment.addBuilds("Melody_" + id, melodyBuilder);*/
        --sectionsToBuild;
      }
      sections[current]->addControl(sections[selection], ruleEnvironment);
      current = selection;
    }
  }

  return new StructuredGenerator(&ruleEnvironment, sections[0]);
}
