#include "../include/RhythmicNote.h"

double RhythmicNote::getLength()
{
  return double(mNumerator) / double(mDenominator);
}

double RhythmicNote::getStart()
{
  return double(mStartBeat) 
    + (double(mStartNumerator) / double(mStartDenominator))
    + (
        (double(mNumerator) / double(mDenominator))
        * double(mStart)
      )
  ;
}
