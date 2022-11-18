//
// Created by The Duke on 18/11/2022.
//

#ifndef FILEWORDCOUNTER_FILEWRDCOUNTER_H
#define FILEWORDCOUNTER_FILEWRDCOUNTER_H
#include <string>
using namespace std;

class FileWrdCounter {
    private:
        std::string filename;
        std::vector<string> allWords;


    public:
        FileWrdCounter(std::string filename);
        void addWord(string word, vector<string>& words, vector<int>& wordCount);
        int findWordPosition(vector<string>& words, string word);
        void reportToScreen(vector<string>& words, vector<int>& wordCount);
};


#endif //FILEWORDCOUNTER_FILEWRDCOUNTER_H
