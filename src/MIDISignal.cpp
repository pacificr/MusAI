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

std::string MIDISignal::getNoteName()
{
  std::string names[] = {
    "C",
    "C#",
    "D",
    "D#",
    "E",
    "F",
    "F#",
    "G",
    "G#",
    "A",
    "A#",
    "B"
  };

  return names[mKey % 12] + std::to_string(mKey / 12);
}
