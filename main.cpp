#include <iostream>
#include <vector>
#include "FileWrdCounter.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::tolower;

int main() {
    string fileName = "";
    cout << "Enter the name of the file" << endl;
    cin >> fileName;
    FileWrdCounter fileWordCounter = FileWrdCounter(fileName);
    return 0;
}
