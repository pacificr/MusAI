#include "../include/MIDISignal.h"
#include "../include/StructuredGenerator.h"
#include "../include/TestRule.h"
#include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(music_library)
{
    emscripten::class_<MIDISignal>("MIDISignal")
        .constructor()
        .function("getRaw", &MIDISignal::getRaw)
    ;

    emscripten::class_<MIDIStream>("MIDIStream")
        .function("hasNext", &MIDIStream::hasNext)
        .function("getNext", &MIDIStream::getNext)
    ;

    emscripten::class_<StructuredGenerator>("StructuredGenerator")
        .constructor<StructureControl&>()
        .function("getNext", &StructuredGenerator::getNext)
    ;

    emscripten::class_<RuleEnvironment>("RuleEnvironment")
        .constructor()
    ;

    emscripten::class_<INoteProducer>("INoteProducer");

    emscripten::class_<TestRule, emscripten::base<INoteProducer>>("TestRule")
        .constructor<RuleEnvironment&>()
    ;

    emscripten::class_<StructureControl>("StructureControl")
        .constructor<RuleEnvironment&, INoteProducer&>()
        .function("addControl", &StructureControl::addControl)
    ;
}