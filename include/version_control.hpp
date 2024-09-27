#ifndef VERSION_CONTROL_HPP
#define VERSION_CONTROL_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class VersionControl {
    public:
        VersionControl();

        void commit(const std::string& fileName, const std::string& content);
        void rollback(const std::string& fileName, int version);
        void branch(const std::string& branchName);
        void merge(const std::string& branchName);
        void resolveConflict(const std::string& fileName, const std::string& resolution);
        void showHistory(const std::string& fileName) const;
    private:
        struct FileVersion {
            std::string content;
            int versionNumber;
        };

        std::unordered_map<std::string, std::vector<FileVersion>> fileHistory;
        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<FileVersion>>> branches;
        std::string currentBranch;

        int getCurrentVersion(const std::string& fileName)
        const;
};


#endif