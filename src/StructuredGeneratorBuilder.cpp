#include "../include/StructuredGeneratorBuilder.h"

#include "../include/StructuredGenerator.h"
#include "../include/BasicAbsoluteNoteRule.h"
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
  //IBuilder *melodyBuilder = ruleEnvironment.getBuilder("Melody");

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
  Scale* scale = new Scale(sd);
  
  std::vector<int> cd;
  cd.push_back(0);
  cd.push_back(2);
  cd.push_back(4);
  Chord* chord = new Chord(cd);

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

  std::vector<RhythmicNote> n;

  for (int i = 0; i < 20; ++i)
  {
    RhythmicNote r;
    r.mStartBeat = i;
    n.push_back(r);
  }
  Rhythm* rhythm = new Rhythm(n, 10);


  Timeline* timeline = new Timeline();
  timeline->addTrack("test");
  timeline->add(new Tempo(80), "test");
  timeline->add(new Tonic(1), "test");
  timeline->add(scale, "test");
  timeline->add(chord, "test");
  timeline->add(pc, "test");
  timeline->add(rhythm, "test");

  sections[current] = new StructureControl(new TimelineAbsoluteNoteRule(timeline), id);
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
        sections[current] = new StructureControl(new TimelineAbsoluteNoteRule(timeline), id);
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
