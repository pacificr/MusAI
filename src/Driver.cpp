
#include "../include/Theme.h"
#include "../include/StructuredGeneratorBuilder.h"
#include "../include/ScalePitch.h"
#include "../include/ChordPitch.h"
#include "../include/PitchCollection.h"

#include "../include/Logger.h"
#define LOC "driver"

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

  auto generator = theme.getGenerator();

  MIDIStream stream = generator->getNext(16);

  while (stream.hasNext())
  {
    logger.log(LOC, stream.getNext().getNoteName());
    stream.getNext();
  }

  return 0;
}
