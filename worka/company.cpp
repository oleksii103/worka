#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Record {
public:
    string companyName;
    string owner;
    string phone;
    string address;
    string activity;

    Record() = default;

    Record(const string& companyName, const string& owner, const string& phone,
        const string& address, const string& activity)
        : companyName(companyName), owner(owner), phone(phone), address(address), activity(activity) {}

    void display() const {
        cout << "Company Name: " << companyName << "\n"
            << "Owner: " << owner << "\n"
            << "Phone: " << phone << "\n"
            << "Address: " << address << "\n"
            << "Activity: " << activity << "\n"
            << "-----------------------------------\n";
    }
};

class Directory {
private:
    vector<Record> records;
    const string filename = "directory.txt";

    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            records.clear();
            string companyName, owner, phone, address, activity;
            while (getline(file, companyName) &&
                getline(file, owner) &&
                getline(file, phone) &&
                getline(file, address) &&
                getline(file, activity)) {
                records.emplace_back(companyName, owner, phone, address, activity);
            }
            file.close();
        }
    }

    void saveToFile() {
        ofstream file(filename, ios::trunc);
        if (file.is_open()) {
            for (const auto& record : records) {
                file << record.companyName << "\n"
                    << record.owner << "\n"
                    << record.phone << "\n"
                    << record.address << "\n"
                    << record.activity << "\n";
            }
            file.close();
        }
    }

public:
    Directory() {
        loadFromFile();
    }

    void addRecord(const Record& record) {
        records.push_back(record);
        saveToFile();
    }

    void displayAll() const {
        for (const auto& record : records) {
            record.display();
        }
    }

    void searchByCompanyName(const string& name) const {
        for (const auto& record : records) {
            if (record.companyName == name) {
                record.display();
            }
        }
    }

    void searchByOwner(const string& ownerName) const {
        for (const auto& record : records) {
            if (record.owner == ownerName) {
                record.display();
            }
        }
    }

    void searchByPhone(const string& phoneNumber) const {
        for (const auto& record : records) {
            if (record.phone == phoneNumber) {
                record.display();
            }
        }
    }

    void searchByActivity(const string& activityType) const {
        for (const auto& record : records) {
            if (record.activity == activityType) {
                record.display();
            }
        }
    }
};

int main() {
    Directory directory;

    int choice;
    do {
        cout << "Menu:\n"
            << "1. Add a record\n"
            << "2. Display all records\n"
            << "3. Search by company name\n"
            << "4. Search by owner\n"
            << "5. Search by phone number\n"
            << "6. Search by activity\n"
            << "0. Exit\n"
            << "Your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string companyName, owner, phone, address, activity;
            cout << "Company Name: ";
            getline(cin, companyName);
            cout << "Owner: ";
            getline(cin, owner);
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Address: ";
            getline(cin, address);
            cout << "Activity: ";
            getline(cin, activity);
            directory.addRecord(Record(companyName, owner, phone, address, activity));
            break;
        }
        case 2:
            directory.displayAll();
            break;
        case 3: {
            string name;
            cout << "Enter company name: ";
            getline(cin, name);
            directory.searchByCompanyName(name);
            break;
        }
        case 4: {
            string ownerName;
            cout << "Enter owner name: ";
            getline(cin, ownerName);
            directory.searchByOwner(ownerName);
            break;
        }
        case 5: {
            string phoneNumber;
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            directory.searchByPhone(phoneNumber);
            break;
        }
        case 6: {
            string activityType;
            cout << "Enter activity type: ";
            getline(cin, activityType);
            directory.searchByActivity(activityType);
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}