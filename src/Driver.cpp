
#include "../include/ThemeFactory.h"
#include "../include/Describer.h"

#include "../include/Logger.h"
#define LOC "driver"

#include <iostream>
#include <memory>

int main(int argc, char* argv[])
{
  Logger& logger = Logger::instance();
  for (int i = 1; i < argc; ++i)
  {
    logger.enable(argv[i]);
  } 

  Describer d;
  d.registerDefaults();
  logger.log(LOC, d.getDescription());

  std::shared_ptr<Theme> theme = MusAI::getTheme("{\"generator\":[{\"type\":\"StructuredGeneratorBuilder\",\"minSections\":2,\"maxSections\":3,\"noteCollection\":[{\"type\":\"TimelineNoteCollectionBuilder\",\"ingredients\":{\"melody\":[[{\"type\":\"MelodySequenceIngredientBuilder\"}]],\"harmony\":[[{\"type\":\"HarmonySequenceIngredientBuilder\"}]],\"default\":[[{\"type\":\"ProgressionIngredientBuilder\"}],[{\"type\":\"CustomScaleIngredientBuilder\",\"degrees\":[0,1,2,3]},{\"type\":\"ScaleIngredientBuilder\",\"scale\":\"whole tone\"}]]}}]}]}");

  std::shared_ptr<IGenerator> generator = theme->getGenerator();

  MIDIStream stream = generator->getNext(16);

  while (stream.hasNext())
  {
    logger.log(LOC, stream.getNext().getNoteName());
    stream.getNext();
  }

  return 0;
}
