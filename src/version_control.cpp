#include "version_control.hpp"

VersionControl::VersionControl() : currentBranch("main") {}

void VersionControl::commit(const std::string& fileName, const std::string& content) {
    int version = getCurrentVersion(fileName) + 1;
    fileHistory[fileName].push_back({content, version});
    std::cout << " Commited version " << version << " of " << fileName << std::endl;
}
void VersionControl::rollback(const std::string& fileName, int version) {
    if (version <= getCurrentVersion(fileName)) {
        std::cout << "Rolled back to version " << version << " of " << fileName << std::endl;
    } else {
        std::cerr << "Error: Version does not exist.\n";
    }
}
void VersionControl::branch(const std::string& branchName) {
    branches[branchName] = fileHistory;
    currentBranch = branchName;
    std::cout << "Created and switched to branch " << branchName << std::endl;
}
void VersionControl::merge(const std::string& branchName) {
    if (branches.find(branchName) != branches.end()) {
        for (const auto& [fileName, versions] : branches[branchName]) {
            fileHistory[fileName].insert(fileHistory[fileName].end(), versions.begin(), versions.end());
        }
        std::cout << "Merged branch " << branchName << " into " << currentBranch << std::endl;
    } else {
        std::cerr << "Error: Branch does not exist.\n";
    }
}
void VersionControl::resolveConflict(const std::string& fileName, const std::string& resolution) {
    commit(fileName, resolution);
    std::cout << "Conflict resolved for " << fileName << " with new content.\n";
}
void VersionControl::showHistory(const std::string& fileName) const {
    if (fileHistory.find(fileName) != fileHistory.end()) {
        for (const auto& version : fileHistory.at(fileName)) {
            std::cout << "Version " << version.versionNumber << ": " << version.content << std::endl;
        }
    } else {
        std::cout << "No history avalibe for " << fileName << std::endl;
    }
}
int VersionControl::getCurrentVersion(const std::string& fileName) const {
    if (fileHistory.find(fileName) != fileHistory.end() && !fileHistory.at(fileName).empty()) {
        return fileHistory.at(fileName).back().versionNumber;
    }
    return 0;

}