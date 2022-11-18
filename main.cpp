#include <iostream>
#include <fstream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::tolower;

class FileWrdCounter {
private:
    std::string filename;
    std::vector<string> allWords;

public:
    FileWrdCounter(std::string filename){
        std::string word;
        vector<string> wordList;
        vector<string> wordEntries;
        vector<int> wordCounts;

        ifstream myFile;
        myFile.open(filename.c_str());
        if (myFile.is_open())
        {
            // extracting words from the file /Users/duke/Downloads/github-recovery-codes-copy.txt
            while (myFile >> word)
            {
                // process the word
                addWord(word, allWords, wordCounts);
            }
            myFile.close();
            cout << "Words " << allWords.size() << " counts " << wordCounts.size();
            reportToScreen(allWords, wordCounts);
        }

        else cout << "Unable to open file";
    }

    void addWord(string word, vector<string> &words, vector<int> &wordCount) {
        vector<string>::iterator witr;
        int index = findWordPosition(words, word);

        if (index == -1) {
            wordCount.push_back(1);
            allWords.push_back(word);
        } else {
            wordCount[index] = wordCount[index]+1;
        }
    }

    int findWordPosition(vector<string> &words, string word) {
        auto itr = find(words.begin(), words.end(), word);
        if (itr != words.end())
        {
            int index = distance(words.begin(), itr);
            return index;
        }
        else {
            return -1;
        }
    }

    void reportToScreen(vector<string>& words, vector<int>& wordCount) {
        for(int i=0; i < allWords.size(); i++)
            std::cout << allWords.at(i) << " - " << wordCount.at(i) << endl;
    }
};




int main() {
    string fileName = "";
    cout << "Enter the name of the file" << endl;
    cin >> fileName;
    FileWrdCounter fileWordCounter = FileWrdCounter(fileName);
    return 0;
}
