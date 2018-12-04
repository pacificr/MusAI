#include "../include/MIDISignal.h"
#include "../include/TestRule.h"
#include "../include/BasicAbsoluteNoteRule.h"
#include "../include/AbsoluteTonicRule.h"
#include "../include/AbsoluteSubdivisionRule.h"
#include "../include/AbsoluteTempoRule.h"
#include "../include/Theme.h"
#include "../include/BasicScaleRule.h"
#include "../include/ScaleChordProgressionRule.h"
#include "../include/StepMelodyBuilder.h"
#include "../include/BasicHarmonyRule.h"
#include "../include/StructuredGeneratorBuilder.h"
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(music_library)
{
    enum_<SCALE>("SCALE")
        .value("MAJOR", SCALE::MAJOR)
        .value("MINOR", SCALE::MINOR)
        .value("IONIAN", SCALE::IONIAN)
        .value("DORIAN", SCALE::DORIAN)
        .value("PHRYGIAN", SCALE::PHRYGIAN)
        .value("LYDIAN", SCALE::LYDIAN)
        .value("MIXOLYDIAN", SCALE::MIXOLYDIAN)
        .value("AEOLIAN", SCALE::AEOLIAN)
        .value("LOCRIAN", SCALE::LOCRIAN)
        ;
    
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

    class_<IRelativeNoteRule, base<IRule>>("IRelativeNoteRule");

    class_<TestRule, base<IRelativeNoteRule>>("TestRule")
        .constructor()
    ;

    class_<BasicHarmonyRule, base<IRelativeNoteRule>>("BasicHarmonyRule")
        .constructor()
    ;

    class_<ITonicRule, base<IRule>>("ITonicRule");

    class_<AbsoluteTonicRule, base<ITonicRule>>("AbsoluteTonicRule")
        .constructor<int>()
    ;

    class_<ISubdivisionRule, base<IRule>>("ISubdivisionRule");

    class_<AbsoluteSubdivisionRule, base<ISubdivisionRule>>("AbsoluteSubdivisionRule")
        .constructor<int>()
    ;

    class_<ITempoRule, base<IRule>>("ITempoRule");

    class_<AbsoluteTempoRule, base<ITempoRule>>("AbsoluteTempoRule")
        .constructor<double>()
    ;

    class_<IScaleRule, base<IRule>>("IScaleRule");

    class_<BasicScaleRule, base<IScaleRule>>("BasicScaleRule")
        .constructor<SCALE>()
    ;

    class_<IChordProgressionRule, base<IRule>>("IChordProgressionRule");

    class_<ScaleChordProgressionRule, base<IChordProgressionRule>>("ScaleChordProgressionRule")
        .constructor<std::vector<int>>()
    ;

    class_<IGenerator, base<IRule>>("IGenerator")
        .function("getNext", &IGenerator::getNext)
    ;

    class_<IBuilder, base<IRule>>("IBuilder");

    class_<StepMelodyBuilder, base<IBuilder>>("StepMelodyBuilder")
        .constructor();
    ;

    class_<StructuredGeneratorBuilder, base<IBuilder>>("StructuredGeneratorBuilder")
        .constructor();
    ;

    register_vector<int>("IntVector");

    class_<Theme>("Theme")
        .constructor()
        .function("addRule", &Theme::addRule)
        .function("getGenerator", &Theme::getGenerator, allow_raw_pointers())
    ;
}