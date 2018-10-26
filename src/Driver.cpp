#include "../include/StructuredGenerator.h"
#include "../include/TestRule.h"
#include "../include/RuleEnvironment.h"

#include <iostream>
#include <memory>

int main()
{
    srand(time(NULL));

    StructuredGenerator generator;
    MIDIStream stream = generator.getNext(1);

    while (stream.hasNext())
    {
        std::cout << stream.getNext().getRaw() << std::endl;
    }

    std::shared_ptr<IRule> r1((IRule *)new TestRule());
    std::shared_ptr<IRule> r2((IRule *)new TestRule());

    RuleEnvironment e;

    e.add("test", std::shared_ptr<IRule>(r1));
    e.add("test", std::shared_ptr<IRule>(r2));

    auto r3 = e.get("test");

    if (r1 == r3)
    {
        std::cout << "got r1";
    }
    else if (r2 == r3)
    {
        std::cout << "get r2";
    }

    return 0;
}