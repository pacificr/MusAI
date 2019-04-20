
#include "../include/ThemeFactory.h"
#include "../include/Describer.h"

#include "../include/Logger.h"
#define LOC "driver"

#include <iostream>
#include <memory>
#include <fstream>

int main(int argc, char* argv[])
{
  Logger& logger = Logger::instance();
  for (int i = 2; i < argc; ++i)
  {
    logger.enable(argv[i]);
  } 

  std::ifstream testJson(argv[1]);
  std::string testJsonString;
  std::getline(testJson, testJsonString);

  logger.log(LOC, "Input: " + testJsonString + "\n");

  Describer d;
  d.registerDefaults();
  logger.log(LOC, "Description:" + d.getDescription() + "\n");

  std::shared_ptr<Theme> theme = MusAI::getTheme(testJsonString);

  std::shared_ptr<IGenerator> generator = theme->getGenerator();

  for (int i = 0; i < 1; i++)
  {
    MIDIStream stream = generator->getNext(i * 20 + 20);

    while (stream.hasNext())
    {
      logger.log(LOC, stream.getNext().getNoteName());
      stream.getNext();
    }
  }

  return 0;
}
