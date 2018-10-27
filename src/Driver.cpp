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
    StructuredGenerator generator(sc);
    
    MIDIStream stream = generator.getNext(1);

    while (stream.hasNext())
    {
        std::cout << stream.getNext().getRaw() << std::endl;
    }

    return 0;
}