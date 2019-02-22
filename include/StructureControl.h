#pragma once

#include "INoteCollection.h"
#include "BuilderSet.h"

#include <memory>
#include <set>

class StructureControl
{
private:
  std::vector<std::weak_ptr<StructureControl>> mControls;
  std::shared_ptr<INoteCollection> mNoteCollection;
public:
  StructureControl(std::shared_ptr<INoteCollection>);

  void addControl(std::weak_ptr<StructureControl>);

  INoteCollection& getNoteCollection() const;
  std::shared_ptr<StructureControl> getNext() const;
};
