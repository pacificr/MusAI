#include "../include/Logger.h"

#include <iostream>

Logger& Logger::instance()
{
  static Logger instance;
  return instance;
}

void Logger::enable(std::string location)
{
  mLocations.insert(location);
  if (location == "all")
    mPrintAll = true;
}

void Logger::log(std::string location, std::string message) const
{
  if (mPrintAll || mLocations.find(location) != mLocations.end())
  {
    std::cout << location << ": " << message << std::endl;
  }
}
