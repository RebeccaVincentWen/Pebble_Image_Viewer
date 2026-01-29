
#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <filesystem>
#include <queue>

#define EndofHistoryCache "EoHC"

namespace File_Processing{

inline std::vector<std::string> imagePaths_temp;
inline std::string cacheFileName = "Application_Cache.txt";

class FileProcessor{
    private:
    std::deque<std::string> HistoryStorage;
    std::weak_ptr<std::string> movablePointer_ToCurrentPosition;

    public:
    FileProcessor(){
        
    }

    std::deque<std::string> GettheDeque(){return HistoryStorage;}

    void temporarilyStoreHistory(std::string& inputHistoryLink){
        HistoryStorage.push_back(inputHistoryLink);
    }

    void writeToHistoryCache(std::string& Path_and_FileName){
        bool tempresult = std::filesystem::exists(cacheFileName);
        if(tempresult == false){
            std::ofstream creationOfCacheFile(cacheFileName);
            creationOfCacheFile << "#cache starts";
            creationOfCacheFile.close();
        }

        std::ofstream tempFileStream(cacheFileName);
        tempFileStream << Path_and_FileName;
        tempFileStream.close();
    }

    void ManageCache(std::string& cache_toBeInserted){
        if (cache_toBeInserted == EndofHistoryCache){
            for(std::string item: HistoryStorage){
                writeToHistoryCache(item);
            }

            HistoryStorage.clear();
        }
        else{
            HistoryStorage.push_back(cache_toBeInserted);
        }
    }

    void selectAndScanFolder(std::string& fileExtension, std::string& folderPath, std::deque<std::string>& filePathSet){
        try
        {
            bool filePathExists = std::filesystem::exists(folderPath) && std::filesystem::is_directory(folderPath);
            if(filePathExists == true){
                for(const auto entry: std::filesystem::directory_iterator(folderPath)){
                    if(entry.path().extension() == fileExtension){
                        filePathSet.push_back(entry.path());
                    }
                }
            }
            else{
                std::cerr << "Folder does not exist!\n";
            }
        }
        catch(const std::filesystem::filesystem_error& e)
        {
            std::cerr << "File System Error:" << e.what() << '\n';
        }
    }

    //the member function of the class ends
};

};