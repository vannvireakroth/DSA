#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, double> studentGrades;

    // Task 1: Add these students with their grades
    // - "Dara" : 85.5
    // - "Sokha" : 92.0
    // - "Bopha" : 78.5
    studentGrades["Dara"] = 85.5;
    studentGrades["Sokha"] = 92.0;
    studentGrades["Bopha"] = 78.5;

    // Task 2: Update Dara's grade to 88.5
    studentGrades["Dara"] = 88.5;

    // Task 3: Print all students and their grades
    for (auto student : studentGrades) {
        cout << student.first << " : " << student.second << endl;
    }

    // Task 4: Check if student "Thida" exists
    if (studentGrades.find("Thida") != studentGrades.end()) {
        cout << "Thida exists." << endl;
    } else {
        cout << "Thida does not exist." << endl;
    }

    return 0;
}