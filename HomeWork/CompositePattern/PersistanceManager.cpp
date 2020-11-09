#include "pch.h"
#include "PersistanceManager.h"
#include <fstream>
#include <sstream>

std::string PersistanceManager::currPath =
std::filesystem::current_path().u8string();

void PersistanceManager::write(const std::string& str,
    const std::string& filename)
{
    std::ofstream ofs(filename);
    ofs << str;
    ofs.close();
}

std::string PersistanceManager::read(const std::string& filename)
{
    std::stringstream ss;
    std::string line;
    std::ifstream rfile;
    rfile.open(filename);
    if (rfile.is_open())
    {
        while (std::getline(rfile, line))
        {
            ss << line << std::endl;
        }
        rfile.close();
    }

    return ss.str();
}