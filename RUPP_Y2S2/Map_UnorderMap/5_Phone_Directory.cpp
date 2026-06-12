#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// Task 1: Decide which map type to use and declare it
// Using map so contacts are displayed in alphabetical order
map<string, string> contacts;

// Task 2: Implement these functions
void addContact(string name, string phone) {
    // Add new contact or update existing one
    contacts[name] = phone;
}

void deleteContact(string name) {
    // Delete a contact if exists
    contacts.erase(name);
}

void searchContact(string name) {
    // Search and print contact details
    if (contacts.find(name) != contacts.end()) {
        cout << name << ": " << contacts[name] << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void displayAllContacts() {
    // Display all contacts
    for (auto contact : contacts) {
        cout << contact.first << ": " << contact.second << endl;
    }
}

int main() {

    // Task 3: Test your implementation

    // 1. Add contacts
    addContact("Dara", "012345678");
    addContact("Bopha", "023456789");
    addContact("Sokha", "034567890");

    // 2. Search for "Dara"
    searchContact("Dara");

    // 3. Update Bopha's number to "098765432"
    addContact("Bopha", "098765432");

    // 4. Delete Sokha's contact
    deleteContact("Sokha");

    // 5. Display all contacts
    displayAllContacts();

    return 0;
}