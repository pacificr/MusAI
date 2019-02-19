#include "../include/StructureControl.h"

StructureControl::StructureControl(std::shared_ptr<INoteCollection> structure, std::string id)
  : mNoteCollection(structure), mControlID(id){}

void StructureControl::addControl(std::weak_ptr<StructureControl> structureControl)
{
  mControls.push_back(structureControl);
}

INoteCollection& StructureControl::getNoteCollection() const
{
  return *mNoteCollection;
}

std::shared_ptr<StructureControl> StructureControl::getNext() const
{
  unsigned int choice = rand() % mControls.size();
  auto controlIt = mControls.begin();
  std::advance(controlIt, choice);
  return (*controlIt).lock();
}
