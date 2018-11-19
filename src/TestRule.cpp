#include "../include/TestRule.h"

void TestRule::describe(RuleEnvironment& ruleEnvironment)
{
  ruleEnvironment.addRule("Test", this);
}

std::vector<RelativeNote> TestRule::getRelativeNotes()
{
  std::vector<RelativeNote> ret;

  RelativeNote a;
  RelativeNote b;
  RelativeNote c;
  RelativeNote d;
  RelativeNote e;
  RelativeNote f;
  RelativeNote g;

  a.mPitch = 4;
  a.mBeat = 0;
  a.mSubdivision = 0;
  a.mDurationBeat = 0;
  a.mDurationSubdivision = 1;

  b.mPitch = 4;
  b.mBeat = 0;
  b.mSubdivision = 1;
  b.mDurationBeat = 0;
  b.mDurationSubdivision = 1;

  c.mPitch = 4;
  c.mBeat = 0;
  c.mSubdivision = 3;
  c.mDurationBeat = 0;
  c.mDurationSubdivision = 2;

  d.mPitch = 0;
  d.mBeat = 1;
  d.mSubdivision = 1;
  d.mDurationBeat = 0;
  d.mDurationSubdivision = 1;

  e.mPitch = 4;
  e.mBeat = 1;
  e.mSubdivision = 2;
  e.mDurationBeat = 0;
  e.mDurationSubdivision = 1;

  f.mPitch = 7;
  f.mBeat = 2;
  f.mSubdivision = 0;
  f.mDurationBeat = 1;
  f.mDurationSubdivision = 0;

  g.mPitch = -5;
  g.mBeat = 3;
  g.mSubdivision = 0;
  g.mDurationBeat = 0;
  g.mDurationSubdivision = 2;

  ret.push_back(a);
  ret.push_back(b);
  ret.push_back(c);
  ret.push_back(d);
  ret.push_back(e);
  ret.push_back(f);
  ret.push_back(g);

  return ret;
}

int TestRule::getLength()
{
  return 4;
}