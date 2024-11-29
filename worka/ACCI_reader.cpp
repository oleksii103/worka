#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
public:
    virtual ~FileHandler() = default;

    virtual void Display(const char* path) {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file!" << endl;
            return;
        }

        cout << "File content:" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

class ASCIIFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file!" << endl;
            return;
        }

        cout << "File content in ASCII codes:" << endl;
        char ch;
        while (file.get(ch)) {
            cout << static_cast<int>(ch) << " ";
        }
        cout << endl;
        file.close();
    }
};

//i hate this code because it`s peace of s**t
class BinaryFileHandler : public FileHandler {
public:
    void Display(const char* path) override {
        ifstream file(path, ios::binary);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file!" << endl;
            return;
        }

        cout << "File content in binary:" << endl;
        char ch;
        while (file.get(ch)) {
            PrintBinary(ch);
            cout << " ";
        }
        cout << endl;
        file.close();
    }

private:
    void PrintBinary(char ch) {
        for (int i = 7; i >= 0; --i) {
            cout << ((ch >> i) & 1);
        }
    }
};

int main() {
    /*setlocale(LC_ALL, "ukr");
    setlocale(LC_ALL, "ja_JP8");
    setlocale(LC_ALL, "ar_SA");*/   //it`s do nothing nevermind 

    const char* filePath = "example.txt";

    FileHandler* baseHandler = new FileHandler();     //ok this code part realy created by chat_gpt 
    baseHandler->Display(filePath);
    delete baseHandler;

    FileHandler* asciiHandler = new ASCIIFileHandler();
    asciiHandler->Display(filePath);
    delete asciiHandler;

    FileHandler* binaryHandler = new BinaryFileHandler();
    binaryHandler->Display(filePath);
    delete binaryHandler;

    return 0;
}
//it work but i already hate this code 