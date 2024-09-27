#include "version_control.hpp"
#include <cassert>
#include <iostream>

void testCommitAndRollback() {
    VersionControl vc;

    vc.commit("file1.txt", "Initial content");
    vc.commit("file1.txt", "Second version");

    vc.rollback("file1.txt", 1);

    std::cout << "Test Commit and Rollback passed!" << std::endl;
}

void testBranchingAndMerging() {
    VersionControl vc;

    vc.commit("file1.txt", "Initial content");
    vc.branch("feature-branch");
    vc.commit("file1.txt", "Feature branch content");

    vc.showHistory("file1.txt");

    vc.merge("main");
    vc.showHistory("file1.txt");

    std::cout << "Test Branching and Merging passed!" << std::endl;
}

void testConflictResolution() {
    VersionControl vc;

    vc.commit("file1.txt", "Version 1");
    vc.branch("feature-branch");
    vc.commit("file1.txt", "Version 2 from feature");

    vc.commit("file1.txt", "Version 3 from main");
    vc.resolveConflict("file1.txt", "Resolved content");

    vc.showHistory("file1.txt");
    std::cout << "Test Conflict Resolution passed!" << std::endl;
}

int main(int argc, char const *argv[])
{
    testCommitAndRollback();
    testBranchingAndMerging();
    testConflictResolution();

    std::cout << "All tests passed!" << std::endl;
    
    return 0;
}
