#include "../include/MIDISignal.h"
#include <string>
#include <bitset>

std::string MIDISignal::getRaw() const
{
    std::string output = std::to_string(mTime);
    output += " ";

    if (mNoteOn)
        output += "1001";
    else
        output += "1000";

    output += std::bitset<4>(mChannel).to_string() + " ";
    output += std::bitset<8>(mKey).to_string() + " ";
    output += std::bitset<8>(mVelocity).to_string();

    return output;
}
