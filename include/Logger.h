#pragma once

#include <set>
#include <string>

class Logger
{
  private:
    Logger(){};
    std::set<std::string> mLocations;
    bool mPrintAll = false;
  public:
    static Logger& instance();
    void enable(std::string location);
    void log(std::string location, std::string message) const;

    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;
};
