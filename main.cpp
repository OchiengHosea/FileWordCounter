#include <iostream>
#include "FileWrdCounter.h"

using std::endl;
using std::cout;

int main() {
    string fileName = "";
    cout << "Enter the name of the file" << endl;
    cin >> fileName;
    FileWrdCounter fileWordCounter = FileWrdCounter(fileName);
    return 0;
}
