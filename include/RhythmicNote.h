#pragma once

class RhythmicNote
{
  public:
    int mValue = 1;
    int mSubdivision = 1;

    int mStartBeat = 0;
    int mStartValue = 0;
    int mStartSubdivision = 1;

    bool mStrong = true;

    RhythmicNote(int value = 1, int subdivision = 1, int startBeat = 0, int startValue = 0, int startSubdivision = 1)
      : mValue(value), mSubdivision(subdivision), mStartBeat(startBeat), mStartValue(startValue), mStartSubdivision(startSubdivision){};
};
