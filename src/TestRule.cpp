#include "../include/TestRule.h"

void TestRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Test", this);
}

std::vector<Note> TestRule::getNotes()
{
  std::vector<Note> ret;

  Note a;
  Note b;
  a.mPitch = 2;
  a.mBeat = 0;
  a.mDurationBeat = 1;
  b.mPitch = 4;
  b.mBeat = 1;
  b.mDurationBeat = 1;
  ret.push_back(a);
  ret.push_back(b);

  return ret;
}