#pragma once

class Tempo
{
  public:
    Tempo(double);
    double mBpm;

    double applyTempo(double) const;
};
