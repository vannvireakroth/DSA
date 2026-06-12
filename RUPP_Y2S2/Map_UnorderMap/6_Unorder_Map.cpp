#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<string, vector<int>> studentScores;

    // Task 1: Add these test scores for each student
    // Dara: 85, 90, 88
    // Sokha: 92, 95, 89
    studentScores["Dara"] = {85, 90, 88};
    studentScores["Sokha"] = {92, 95, 89};

    // Task 2: Calculate and print average score for each student
    for (auto student : studentScores) {
        int sum = 0;
        for (int score : student.second) {
            sum += score;
        }
        double average = (double)sum / student.second.size();
        cout << student.first << " Average: " << average << endl;
    }

    // Task 3: Add a new score 93 for Dara
    studentScores["Dara"].push_back(93);

    // Task 4: Print number of scores for each student
    for (auto student : studentScores) {
        cout << student.first << " has "
             << student.second.size()
             << " scores." << endl;
    }

    return 0;
}