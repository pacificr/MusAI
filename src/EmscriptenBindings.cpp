#include "../include/MIDISignal.h"
#include "../include/Theme.h"
#include "../include/StructuredGeneratorBuilder.h"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(music_library)
{ 
    class_<MIDISignal>("MIDISignal")
        .constructor()
        .function("getRaw", &MIDISignal::getRaw)
        .property("isNoteOn", &MIDISignal::mNoteOn)
        .property("channel", &MIDISignal::mChannel)
        .property("key", &MIDISignal::mKey)
        .property("velocity", &MIDISignal::mVelocity)
        .property("time", &MIDISignal::mTime)
    ;

    class_<MIDIStream>("MIDIStream")
        .function("hasNext", &MIDIStream::hasNext)
        .function("getNext", &MIDIStream::getNext)
    ;

    class_<IRule>("IRule");

    class_<IGenerator, base<IRule>>("IGenerator")
        .function("getNext", &IGenerator::getNext)
    ;

    class_<IBuilder, base<IRule>>("IBuilder");

    class_<StructuredGeneratorBuilder, base<IBuilder>>("StructuredGeneratorBuilder")
        .constructor();
    ;

    class_<Theme>("Theme")
        .constructor()
        .function("addRule", &Theme::addRule)
        .function("getGenerator", &Theme::getGenerator, allow_raw_pointers())
    ;
}
