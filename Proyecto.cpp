#include <iostream>
using namespace std;

struct File {
    string data;
    string name;
    string date;
    bool hidden;
    int type;
};

struct FileNode {
    File data;
    FileNode *next;
    FileNode *prev;
    FileNode *down;
    FileNode *parent;
};

FileNode *rootDirectory = new FileNode;

int main(){
    string input;   // Input
    string cwd;     // Current Working Directory

    while (true) {
        cout << "C:/" << cwd << "> ";
        cin >> input;
        if (input == "exit") { break; }
    }
    
    
    return 0;
}
