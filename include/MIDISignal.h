#pragma once

#include <string>

class MIDISignal
{
public:
    bool mNoteOn = false;
    int mChannel = 0;
    int mKey = 0;
    int mVelocity = 0;
    double mTime = 0;

    std::string getRaw() const;
    std::string getNoteName();
};
