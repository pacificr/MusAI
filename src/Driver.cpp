#include "../include/TestRule.h"
#include "../include/Theme.h"
#include "../include/StructuredGeneratorProducer.h"

#include <iostream>
#include <memory>

int main()
{
  srand(time(NULL));

  Theme theme;
  TestRule test;
  StructuredGeneratorProducer p;
  theme.addRule(p);
  theme.addRule(test);
  IGenerator* generator = theme.getGenerator();

  MIDIStream stream = generator->getNext(0.5);

  while (stream.hasNext())
  {
    std::cout << stream.getNext().getRaw() << std::endl;
  }

  stream = generator->getNext(8);

  while (stream.hasNext())
  {
    std::cout << stream.getNext().getRaw() << std::endl;
  }

  delete generator;

  return 0;
}