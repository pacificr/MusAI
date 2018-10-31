#pragma once

#include "IRule.h"
#include "Note.h"

#include <vector>

class INoteProducer : public IRule
{
public:
  virtual ~INoteProducer() = default;
  virtual std::vector<Note> getNotes() = 0;
};