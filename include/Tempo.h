#pragma once

class Tempo
{
  public:
    Tempo(int);
    double mBpm;

    double applyTempo(double);
};
