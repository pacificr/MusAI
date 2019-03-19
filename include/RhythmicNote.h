#pragma once

class RhythmicNote
{
  public:
    int mNumerator;
    int mDenominator;

    int mStart;

    int mStartBeat;
    int mStartNumerator;
    int mStartDenominator;

    RhythmicNote(int numerator = 1, int denominator = 1, int start = 0, int startBeat = 0, int startNumerator = 0, int startDenominator = 1)
      : mNumerator(numerator), mDenominator(denominator), mStart(start), mStartBeat(startBeat), mStartNumerator(startNumerator), mStartDenominator(startDenominator){};

    double getLength();
    double getStart();
};
