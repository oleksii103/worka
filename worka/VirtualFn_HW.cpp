#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
public:
    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file) {
            cerr << "Error: Unable to open file " << path << endl;
            return;
        }

        cout << "File content:\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    virtual ~FileHandler() = default;
};

class AsciiFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file) {
            cerr << "Error: Unable to open file " << path << endl;
            return;
        }

        cout << "File content in ASCII codes:\n";
        char ch;
        while (file.get(ch)) {
            cout << static_cast<int>(ch) << " ";
        }
        cout << endl;
        file.close();
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);
        if (!file) {
            cerr << "Error: Unable to open file " << path << endl;
            return;
        }

        cout << "File content in binary:\n";
        char ch;
        while (file.get(ch)) {
            PrintBinary(static_cast<unsigned char>(ch));
        }
        cout << endl;
        file.close();
    }

private:
    void PrintBinary(unsigned char ch) {
        for (int i = 7; i >= 0; --i) {
            cout << ((ch >> i) & 1); 
        }
        cout << " ";
    }
};

int main() {
    const char* filePath = "example.txt";

    FileHandler* baseHandler = new FileHandler();
    FileHandler* asciiHandler = new AsciiFileHandler();
    FileHandler* binaryHandler = new BinaryFileHandler();

    cout << "Base class output:\n";
    baseHandler->Display(filePath);

    cout << "\nASCII handler output:\n";
    asciiHandler->Display(filePath);

    cout << "\nBinary handler output:\n";
    binaryHandler->Display(filePath);

    delete baseHandler;
    delete asciiHandler;
    delete binaryHandler;

    return 0;
}
