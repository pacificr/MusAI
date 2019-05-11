
#include "../include/ThemeFactory.h"
#include "../include/Describer.h"

#include "../include/Logger.h"
#define LOC "driver"

#include <iostream>
#include <memory>
#include <fstream>
#include <chrono>

int main(int argc, char* argv[])
{
  Logger& logger = Logger::instance();
  int limit = -1;
  for (int i = 2; i < argc; ++i)
  {
    if (strcmp(argv[i],"-l") == 0)
      limit = atoi(argv[++i]);
    else
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

  using namespace std::chrono;
  milliseconds start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  milliseconds current = start;

  int t = 20;
  MIDIStream stream = generator->getNext(t);
  MIDISignal signal = stream.getNext();

  while(limit == -1 || limit > (current.count() - start.count()) / 1000)
  {
    current = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    if ((current.count() - start.count()) / 1000 >= signal.mTime)
    {
      std::cout << signal.getRaw() << std::endl;
      if (stream.hasNext())
      {
        signal = stream.getNext();
      }
      else
      {
        t += 20;
        stream = generator->getNext(t);
        signal = stream.getNext();
      }
    }
  }

  return 0;
}
