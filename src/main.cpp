#include "version_control.hpp"


int main(int argc, char const *argv[])
{
    VersionControl vc;

    vc.commit("file1.txt", "Initial content");
    vc.commit("file1.txt", "Update content");

    vc.branch("feature-branch");
    vc.commit("file1.txt", "Feature branch content");

    vc.showHistory("file1.txt");

    vc.merge("main");
    vc.showHistory("file1.txt");
    
    return 0;
}
