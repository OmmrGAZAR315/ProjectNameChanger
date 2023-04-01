#include <iostream>
#include <fstream>
#include <windows.h>
#include <filesystem>

using namespace std;

void changeCmakeLists(string &content, const string &target, const string &oldName, const string &newName) {
    short pos = content.find(target);
    if (pos != string::npos)
        content.replace(pos + 2, oldName.length(), newName);
}

int main() {
    string oldName;
    cout << "what is your project name: ";
    cin >> oldName;
    string path = R"(C:\Users\omara\CLionProjects\)" + oldName + "\\CMakeLists.txt";
    std::fstream input(path, ios::in | ios::out);
    stringstream buffer;
    buffer << input.rdbuf();
    string content = buffer.str();
    string newName;
    cout << "enter new project name: ";
    cin >> newName;
    changeCmakeLists(content, "t(", oldName, newName);
    changeCmakeLists(content, "e(", oldName, newName);
    input.seekp(0, ios::beg);
//    cout << content;
    filesystem::resize_file(path, 0);
    input << content;
    input.close();
    MoveFile(path.substr(0, 29 + oldName.length()).c_str(), (path.substr(0, 29) + newName).c_str());
    system("pause");
    return 0;
}
