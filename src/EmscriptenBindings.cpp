#include "../include/MIDISignal.h"
#include "../include/StructuredGeneratorRule.h"
#include "../include/TestRule.h"
#include "../include/BasicAbsoluteNoteRule.h"
#include "../include/AbsoluteTonicRule.h"
#include "../include/AbsoluteSubdivisionRule.h"
#include "../include/AbsoluteTempoRule.h"
#include "../include/Theme.h"
#include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(music_library)
{
    emscripten::class_<MIDISignal>("MIDISignal")
        .constructor()
        .function("getRaw", &MIDISignal::getRaw)
        .property("isNoteOn", &MIDISignal::mNoteOn)
        .property("channel", &MIDISignal::mChannel)
        .property("key", &MIDISignal::mKey)
        .property("velocity", &MIDISignal::mVelocity)
        .property("time", &MIDISignal::mTime)
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

    emscripten::class_<ITonicRule, emscripten::base<IRule>>("ITonicRule");

    emscripten::class_<AbsoluteTonicRule, emscripten::base<ITonicRule>>("AbsoluteTonicRule")
        .constructor<int>()
    ;

    emscripten::class_<ISubdivisionRule, emscripten::base<IRule>>("ISubdivisionRule");

    emscripten::class_<AbsoluteSubdivisionRule, emscripten::base<ISubdivisionRule>>("AbsoluteSubdivisionRule")
        .constructor<int>()
    ;

    emscripten::class_<ITempoRule, emscripten::base<IRule>>("ITempoRule");

    emscripten::class_<AbsoluteTempoRule, emscripten::base<ITempoRule>>("AbsoluteTempoRule")
        .constructor<double>()
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