#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string text = "the quick brown fox jumps over the lazy dog the fox";
    unordered_map<string, int> wordFreq;

    // Task 1: Count frequency of each word
    stringstream ss(text);
    string word;

    while (ss >> word) {
        wordFreq[word]++;
    }

    // Task 2: Print words that appear more than once
    cout << "Words appearing more than once:" << endl;
    for (auto item : wordFreq) {
        if (item.second > 1) {
            cout << item.first << " : " << item.second << endl;
        }
    }

    // Task 3: Find the word with highest frequency
    string maxWord;
    int maxFreq = 0;

    for (auto item : wordFreq) {
        if (item.second > maxFreq) {
            maxFreq = item.second;
            maxWord = item.first;
        }
    }

    cout << "Most frequent word: " << maxWord
         << " (" << maxFreq << " times)" << endl;

    return 0;
}
