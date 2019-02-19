#pragma once

#include "Note.h"

#include <vector>

class INoteCollection
{
public:
  virtual ~INoteCollection() = default;
  virtual std::vector<Note> getNotes() const = 0;
  virtual double getLength() const = 0;
};
