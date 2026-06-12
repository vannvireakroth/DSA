#include <iostream>
using namespace std;

#define SIZE 200

string table[SIZE];

int hashFunction(string key) {
    int p = 31, hash = 0, power = 1;
    for (char c : key) {
        hash = (hash + c * power) % SIZE;
        power = (power * p) % SIZE;
    }
    return hash;
}

void insert(string key) {
    int index = hashFunction(key);
    while (table[index] != "") {
        index = (index + 1) % SIZE;
    }
    table[index] = key;
}

bool search(string key) {
    int index = hashFunction(key);
    int start = index;
    while (table[index] != "") {
        if (table[index] == key)
            return true;
        index = (index + 1) % SIZE;
        if (index == start) break;
    }
    return false;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == "")
            cout << i << ": -" << endl;
        else
            cout << i << ": " << table[i] << endl;
    }
}

int main() {
    int choice;
    string key;

    do {
        cout << "\n=== Hash Table Menu ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                insert(key);
                cout << "\"" << key << "\" inserted." << endl;
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                if (search(key))
                    cout << "\"" << key << "\" Found." << endl;
                else
                    cout << "\"" << key << "\" Not Found." << endl;
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}