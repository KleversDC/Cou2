#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Contact {
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    void Input() {
        cout << "Enter full name: ";
        getline(cin, fullName);
        cout << "Enter home phone: ";
        getline(cin, homePhone);
        cout << "Enter work phone: ";
        getline(cin, workPhone);
        cout << "Enter mobile phone: ";
        getline(cin, mobilePhone);
    }
    void Display() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
    }
};
class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void AddContact() {
        Contact newContact;
        newContact.Input();
        contacts.push_back(newContact);
    }
    void DisplayAllContacts() const {
        if (contacts.empty()) {
            cout << "Phone book is empty." << endl;
        }
        else {
            for (size_t i = 0; i < contacts.size(); i++) {
                cout << "Contact " << i + 1 << ":" << endl;
                contacts[i].Display();
                cout << endl;
            }
        }
    }
    void SearchByFullName(const string& fullName) const {
        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.fullName == fullName) {
                contact.Display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found." << endl;
        }
    }
    void RemoveContact(const string& fullName) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->fullName == fullName) {
                contacts.erase(it);
                cout << "Contact removed." << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
};
int main() {
    PhoneBook phoneBook;
    int choice;
    string fullName;

    do {
        cout << "\nPhone Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact by Full Name\n";
        cout << "4. Remove Contact by Full Name\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            phoneBook.AddContact();
            break;
        case 2:
            phoneBook.DisplayAllContacts();
            break;
        case 3:
            cout << "Enter full name to search: ";
            getline(cin, fullName);
            phoneBook.SearchByFullName(fullName);
            break;
        case 4:
            cout << "Enter full name to remove: ";
            getline(cin, fullName);
            phoneBook.RemoveContact(fullName);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 0);
}
