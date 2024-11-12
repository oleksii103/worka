#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int _size;

public:
    Stack() : top(nullptr), _size(0) {}

    // Add an element to the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        _size++;
        cout << "Element " << value << " pushed onto the stack." << endl;
    }

    // Remove an element from the stack
    int pop() {
        if (isEmpty()) {
            cerr << "Stack is empty!" << endl;
            return -1;
        }
        int poppedValue = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        _size--;
        cout << "Element " << poppedValue << " popped from the stack." << endl;
        return poppedValue;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Return the size of the stack
    int size() const {
        return _size;
    }
};

int main() {
    Stack stack;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Push element onto the stack\n";
        cout << "2. Pop element from the stack\n";
        cout << "3. Display stack size\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Current stack size: " << stack.size() << endl;
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
