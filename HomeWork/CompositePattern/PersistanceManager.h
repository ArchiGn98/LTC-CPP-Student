#pragma once
#include <string>
#include <filesystem>

class PersistanceManager
{
    static std::string currPath;

public:
    static void write(const std::string& str, const std::string& filename);

    static std::string read(const std::string& filename);

    inline static std::string getCurrPath() { return currPath; }
};