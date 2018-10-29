#include "../include/StructuredGenerator.h"
#include "../include/TestRule.h"
#include "../include/RuleEnvironment.h"

#include <iostream>
#include <memory>

int main()
{
    srand(time(NULL));

    RuleEnvironment re;
    TestRule test(re);
    StructureControl sc(re, test);
    sc.addControl(sc);
    StructuredGenerator generator(sc);
    
    MIDIStream stream = generator.getNext(0.5);

    while (stream.hasNext())
    {
        std::cout << stream.getNext().getRaw() << std::endl;
    }
    
    stream = generator.getNext(8);

    while (stream.hasNext())
    {
        std::cout << stream.getNext().getRaw() << std::endl;
    }

    return 0;
}