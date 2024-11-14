#include <iostream>
#include <string>

using namespace std;

struct Violation {
    string description;
    int amount;
    Violation(const string& desc, int amt) : description(desc), amount(amt) {}
};

struct Node {
    string carNumber;
    Violation violations[10];
    int violationCount = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(const string& number) : carNumber(number) {};

    void addViolation(const string& description, int amount) {
        if (violationCount < 10)
            violations[violationCount++] = Violation(description, amount);
        else
            cout << "Max violations reached for car number: " << carNumber << endl;
    }
};

class TrafficDatabase {
    Node* root = nullptr;

    Node* addViolation(Node* node, const string& carNumber, const string& description, int amount) {
        if (!node) return new Node(carNumber);

        if (carNumber < node->carNumber)
            node->left = addViolation(node->left, carNumber, description, amount);
        else if (carNumber > node->carNumber)
            node->right = addViolation(node->right, carNumber, description, amount);
        else
            node->addViolation(description, amount);

        return node;
    }

    void printAll(Node* node) {
        if (!node) return;
        printAll(node->left);
        cout << "Car Number: " << node->carNumber << endl;
        for (int i = 0; i < node->violationCount; ++i)
            cout << "  Violation: " << node->violations[i].description
            << ", Amount: " << node->violations[i].amount << endl;
        printAll(node->right);
    }

    Node* find(Node* node, const string& carNumber) {
        if (!node || node->carNumber == carNumber) return node;
        return carNumber < node->carNumber ? find(node->left, carNumber) : find(node->right, carNumber);
    }

public:
    void addViolation(const string& carNumber, const string& description, int amount) {
        root = addViolation(root, carNumber, description, amount);
    }

    void printAll() {
        printAll(root);
    }

    void printByCarNumber(const string& carNumber) {
        Node* node = find(root, carNumber);
        if (node) {
            cout << "Car Number: " << node->carNumber << endl;
            for (int i = 0; i < node->violationCount; ++i)
                cout << "  Violation: " << node->violations[i].description
                << ", Amount: " << node->violations[i].amount << endl;
        }
        else {
            cout << "No data found for car number: " << carNumber << endl;
        }
    }
};

void displayMenu() {
    cout << "\nMenu:\n"
        << "1. Add Violation\n"
        << "2. Print All Violations\n"
        << "3. Print Violations by Car Number\n"
        << "4. Exit\n> ";
}

int main() {
    TrafficDatabase db;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore the newline character

        if (choice == 1) {
            string carNumber, description;
            int amount;
            cout << "Enter car number: "; getline(cin, carNumber);
            cout << "Enter violation description: "; getline(cin, description);
            cout << "Enter amount: "; cin >> amount;
            db.addViolation(carNumber, description, amount);

        }
        else if (choice == 2) {
            db.printAll();

        }
        else if (choice == 3) {
            string carNumber;
            cout << "Enter car number: "; cin >> carNumber;
            db.printByCarNumber(carNumber);

        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;

        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
/*code created with chat gpt help deacose i have not idea
come on it`s 03.00AM of course a havent ideas
a oh f***c it doest work*/