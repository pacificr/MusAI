
#include "../include/ThemeFactory.h"
#include "../include/StructuredGeneratorBuilder.h"
#include "../include/TimelineNoteCollectionBuilder.h"

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

  std::shared_ptr<Theme> theme = MusAI::getTheme("{\"generator\": [{\"builder\": \"StructuredGeneratorBuilder\",\"minSections\": 2,\"maxSections\": 3,\"noteCollection\": [{\"builder\": \"TimelineNoteCollectionBuilder\"}]}]}");

  std::shared_ptr<IGenerator> generator = theme->getGenerator();

  MIDIStream stream = generator->getNext(16);

  while (stream.hasNext())
  {
    logger.log(LOC, stream.getNext().getNoteName());
    stream.getNext();
  }

  return 0;
}
