
#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <filesystem>

namespace File_Processing{

std::vector<std::string> imagePaths_temp;
std::string cacheFile = "Application_Cache.txt";

class FileProcessor{
    private:
    public:
    void writeToHistoryCache(std::string Path_and_FileName){
        bool tempresult = std::filesystem::exists(cacheFile);
        if(tempresult == false){
            std::ofstream creationOfCacheFile(cacheFile);
            creationOfCacheFile << "#cache starts";
            creationOfCacheFile.close();
        }

        std::ofstream tempFileStream(cacheFile);
        tempFileStream << Path_and_FileName;
        tempFileStream.close();
    }
};

};