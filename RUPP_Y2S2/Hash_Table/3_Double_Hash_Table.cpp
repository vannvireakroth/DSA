#include <iostream>
using namespace std;

#define SIZE 199

string table[SIZE];
bool deleted[SIZE] = {false};

int hash1(string key) {
    int p = 31, hash = 0, power = 1;
    for (char c : key) {
        hash = (hash + c * power) % SIZE;
        power = (power * p) % SIZE;
    }
    return hash;
}

int hash2(string key) {
    int p = 37, hash = 0, power = 1;
    for (char c : key) {
        hash = (hash + c * power) % (SIZE - 1);
        power = (power * p) % (SIZE - 1);
    }
    return hash + 1; 
}

void insert(string key) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    int i = 0;

    while (i < SIZE) {
        int index = (h1 + i * h2) % SIZE;
        if (table[index] == "" || deleted[index]) {
            table[index] = key;
            deleted[index] = false;
            return;
        }
        i++;
    }
    cout << "Hash table is full!" << endl;
}

bool search(string key) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    int i = 0;

    while (i < SIZE) {
        int index = (h1 + i * h2) % SIZE;
        if (table[index] == "" && !deleted[index])
            break;
        if (!deleted[index] && table[index] == key)
            return true;
        i++;
    }
    return false;
}

bool deleteKey(string key) {
    int h1 = hash1(key);
    int h2 = hash2(key);
    int i = 0;

    while (i < SIZE) {
        int index = (h1 + i * h2) % SIZE;
        if (table[index] == "" && !deleted[index])
            break;
        if (!deleted[index] && table[index] == key) {
            table[index] = "";
            deleted[index] = true;
            return true;
        }
        i++;
    }
    return false;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (deleted[i])
            cout << i << ": tombstone" << endl;
        else if (table[i] == "")
            cout << i << ": -" << endl;
        else
            cout << i << ": " << table[i] << endl;
    }
}

int main() {
    int choice;
    string key;

    do {
        cout << "\n=== Double Hash Table Menu ===" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
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
                cout << "Enter key to delete: ";
                cin >> key;
                if (deleteKey(key))
                    cout << "\"" << key << "\" deleted." << endl;
                else
                    cout << "\"" << key << "\" Not Found." << endl;
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
        
    } while (choice != 5);

    return 0;
}