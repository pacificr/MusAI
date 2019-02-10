#include "../include/Tempo.h"

Tempo::Tempo(int bpm)
  : mBpm(bpm){}

double Tempo::applyTempo(double beat)
{
  return (60.0 / mBpm) * beat;
}
