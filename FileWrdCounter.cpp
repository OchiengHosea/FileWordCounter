//
// Created by The Duke on 18/11/2022.
//
#include <iostream>
#include <vector>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::tolower;
#include "FileWrdCounter.h"

using namespace std;
using std::ifstream;
using std::tolower;

FileWrdCounter::FileWrdCounter(std::string filename) {
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

void FileWrdCounter::addWord(string word, vector<string> &words, vector<int> &wordCount) {
    vector<string>::iterator witr;
    int index = findWordPosition(words, word);

    if (index == -1) {
        wordCount.push_back(1);
        allWords.push_back(word);
    } else {
        wordCount[index] = wordCount[index]+1;
    }
}

int FileWrdCounter::findWordPosition(vector<string> &words, string word) {
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

void FileWrdCounter::reportToScreen(vector<string>& words, vector<int>& wordCount) {
    for(int i=0; i < allWords.size(); i++)
        std::cout << allWords.at(i) << " - " << wordCount.at(i) << endl;
}