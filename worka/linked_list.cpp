#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

    // Helper function to add elements to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            for (; temp->next != nullptr; temp = temp->next);
            temp->next = newNode;
        }
    }

public:
    LinkedList() : head(nullptr) {}

    // Adds an element to the end of the list
    void add(int value) {
        append(value);
    }

    // Clones the list and returns the head of the cloned list
    Node* clone() const {
        if (!head) return nullptr;

        Node* newHead = new Node(head->value);
        Node* currentNew = newHead;
        Node* currentOld = head->next;

        for (; currentOld != nullptr; currentOld = currentOld->next) {
            currentNew->next = new Node(currentOld->value);
            currentNew = currentNew->next;
        }
        return newHead;
    }

    // Overloading the '+' operator for list concatenation
    LinkedList operator+(const LinkedList& other) const {
        LinkedList result;
        for (Node* current = this->head; current != nullptr; current = current->next) {
            result.append(current->value);
        }

        for (Node* current = other.head; current != nullptr; current = current->next) {
            result.append(current->value);
        }

        return result;
    }

    // Overloading the '*' operator for list intersection
    LinkedList operator*(const LinkedList& other) const {
        LinkedList result;
        for (Node* current = this->head; current != nullptr; current = current->next) {
            for (Node* otherCurrent = other.head; otherCurrent != nullptr; otherCurrent = otherCurrent->next) {
                if (current->value == otherCurrent->value) {
                    result.append(current->value);
                    break;
                }
            }
        }
        return result;
    }

    // Print elements of the list
    void print() const {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            cout << temp->value << " ";
        }
        cout << endl;
    }
};

int main() {
    LinkedList list1, list2, result;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add element to List 1\n";
        cout << "2. Add element to List 2\n";
        cout << "3. Clone List 1\n";
        cout << "4. Combine List 1 and List 2\n";
        cout << "5. Intersect List 1 and List 2\n";
        cout << "6. Display List 1\n";
        cout << "7. Display List 2\n";
        cout << "8. Display Result\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to add to List 1: ";
            cin >> value;
            list1.add(value);
            break;
        case 2:
            cout << "Enter value to add to List 2: ";
            cin >> value;
            list2.add(value);
            break;
        case 3: {
            Node* clonedHead = list1.clone();
            result = LinkedList(); // Clear result list
            for (Node* current = clonedHead; current != nullptr; current = current->next) {
                result.add(current->value);
            }
            cout << "List 1 has been cloned into Result.\n";
            break;
        }
        case 4:
            result = list1 + list2;
            cout << "List 1 and List 2 have been combined into Result.\n";
            break;
        case 5:
            result = list1 * list2;
            cout << "Intersection of List 1 and List 2 has been stored in Result.\n";
            break;
        case 6:
            cout << "List 1: ";
            list1.print();
            break;
        case 7:
            cout << "List 2: ";
            list2.print();
            break;
        case 8:
            cout << "Result: ";
            result.print();
            break;
        case 9:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
