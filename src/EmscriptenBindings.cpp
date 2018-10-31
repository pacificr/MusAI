#include "../include/MIDISignal.h"
#include "../include/StructuredGeneratorProducer.h"
#include "../include/TestRule.h"
#include "../include/Theme.h"
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

    emscripten::class_<IGenerator>("IGenerator")
        .function("getNext", &IGenerator::getNext)
    ;

    emscripten::class_<IRule>("IRule");

    emscripten::class_<INoteProducer, emscripten::base<IRule>>("INoteProducer");

    emscripten::class_<TestRule, emscripten::base<INoteProducer>>("TestRule")
        .constructor()
    ;

    emscripten::class_<IGeneratorProducer, emscripten::base<IRule>>("IGeneratorProducer");

    emscripten::class_<StructuredGeneratorProducer, emscripten::base<IGeneratorProducer>>("StructuredGeneratorProducer")
        .constructor()
    ;

    emscripten::class_<Theme>("Theme")
        .constructor()
        .function("addRule", &Theme::addRule)
        .function("getGenerator", &Theme::getGenerator, emscripten::allow_raw_pointers())
    ;
}