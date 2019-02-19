#include "../include/Tempo.h"

Tempo::Tempo(double bpm)
  : mBpm(bpm){}

double Tempo::applyTempo(double beat) const
{
  return (60.0 / mBpm) * beat;
}
