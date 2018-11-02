#include "../include/MIDISignal.h"
#include "../include/StructuredGeneratorRule.h"
#include "../include/TestRule.h"
#include "../include/BasicAbsoluteNoteRule.h"
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

    emscripten::class_<IRelativeNoteRule, emscripten::base<IRule>>("IRelativeNoteRule");

    emscripten::class_<TestRule, emscripten::base<IRelativeNoteRule>>("TestRule")
        .constructor()
    ;

    emscripten::class_<IAbsoluteNoteRule, emscripten::base<IRule>>("IAbsoluteNoteRule");

    emscripten::class_<BasicAbsoluteNoteRule, emscripten::base<IAbsoluteNoteRule>>("BasicAbsoluteNoteRule")
        .constructor()
    ;

    emscripten::class_<IGeneratorRule, emscripten::base<IRule>>("IGeneratorRule");

    emscripten::class_<StructuredGeneratorRule, emscripten::base<IGeneratorRule>>("StructuredGeneratorRule")
        .constructor()
    ;

    emscripten::class_<Theme>("Theme")
        .constructor()
        .function("addRule", &Theme::addRule)
        .function("getGenerator", &Theme::getGenerator, emscripten::allow_raw_pointers())
    ;
}