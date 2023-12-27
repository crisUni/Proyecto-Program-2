#include <iostream>
#include <chrono>
using namespace std;

#define NL cout << "\n"

struct File {
    string name;
    string date;
    bool hidden;
    int type; // 1 = Dir 0 = File
};

struct FileNode {
    File data;
    FileNode *next;
    FileNode *prev;
    FileNode *down;
    FileNode *parent;
};

// Reference moment https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
const string GetDate(string format = "%Y-%m-%d %X") {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), &format[0], &tstruct);
    return buf;
};

FileNode *rootDirectory = new FileNode;
string input;   // Input
string cwd;     // Current Working Directory

/*
    Create File and Directory
*/

void CreateFile(FileNode *&dir, string name, bool hidden) {
    FileNode* aux = dir->down;

    dir->down->data.name = name;
    dir->down->data.hidden = hidden;
    dir->down->data.date = GetDate();
    dir->down->data.type = 0;
    
    dir->down->down = NULL;
    dir->down->parent = dir;
}


int main(){
    rootDirectory->next = NULL;
    rootDirectory->prev = NULL;
    rootDirectory->down = NULL;
    rootDirectory->parent = NULL;
    rootDirectory->data.name = "C:";
    rootDirectory->data.date = GetDate(); // TODO: Make dates
    rootDirectory->data.hidden = false;
    rootDirectory->data.type = 1;

    while (true) {
        cout << "C:/" << cwd << "> ";
        cin >> input;
        if (input == "date") { cout << GetDate(); NL; }
        if (input == "exit") { break; }
    }
    
    
    return 0;
}
