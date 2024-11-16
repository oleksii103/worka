#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const float Pi = 3.141592653589793;

class Figures {
public:
    virtual float Area() = 0;
    virtual float Perimeter() = 0;
    virtual ~Figures() {}
    virtual void PrintToFile(ofstream& outfile) = 0;
    virtual void PrintFromFile(ifstream& infile) = 0;
};

class Parallelogram : public Figures {
protected:
    int SideA, SideB, Angle;
public:
    Parallelogram() : SideA(1), SideB(2), Angle(45) {}
    Parallelogram(int sideA, int sideB, int angle) : SideA(sideA), SideB(sideB), Angle(angle) {}

    float Area() override {
        float angleRadians = Angle * Pi / 180.0;
        return SideA * SideB * sin(angleRadians);
    }

    float Perimeter() override {
        return 2 * (SideA + SideB);
    }

    void PrintToFile(ofstream& outfile) override {
        outfile << "Parallelogram: " << SideA << ", " << SideB << ", " << Angle << " degrees." << endl;
        outfile << "Area: " << Area() << ", Perimeter: " << Perimeter() << endl;
    }

    void PrintFromFile(ifstream& infile) override {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle() : Parallelogram(1, 2, 90) {}
    Rectangle(int sideA, int sideB) : Parallelogram(sideA, sideB, 90) {}

    void PrintToFile(ofstream& outfile) override {
        outfile << "Rectangle: " << SideA << " x " << SideB << endl;
        outfile << "Area: " << Area() << ", Perimeter: " << Perimeter() << endl;
    }

    void PrintFromFile(ifstream& infile) override {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
};

class Circle : public Figures {
private:
    int R;
public:
    Circle() : R(5) {}
    Circle(int r) : R(r) {}

    float Area() override {
        return Pi * R * R;
    }

    float Perimeter() override {
        return 2 * Pi * R;
    }

    void PrintToFile(ofstream& outfile) override {
        outfile << "Circle with radius: " << R << endl;
        outfile << "Area: " << Area() << ", Perimeter: " << Perimeter() << endl;
    }

    void PrintFromFile(ifstream& infile) override {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
};

class D3Figure {
public:
    virtual double Volume() = 0;
    virtual double FullArea() = 0;
    virtual ~D3Figure() {}
    virtual void PrintToFile(ofstream& outfile) = 0;
    virtual void PrintFromFile(ifstream& infile) = 0;
};

class Cube : public D3Figure {
private:
    int Side;
public:
    Cube() : Side(1) {}
    Cube(int side) : Side(side) {}

    double Volume() override {
        return Side * Side * Side;
    }

    double FullArea() override {
        return 6 * Side * Side;
    }

    void PrintToFile(ofstream& outfile) override {
        outfile << "Cube with side: " << Side << endl;
        outfile << "Volume: " << Volume() << ", Full Area: " << FullArea() << endl;
    }

    void PrintFromFile(ifstream& infile) override {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
};

class Sphere : public D3Figure {
private:
    int R;
public:
    Sphere() : R(1) {}
    Sphere(int r) : R(r) {}

    double Volume() override {
        return (4.0 / 3.0) * Pi * R * R * R;
    }

    double FullArea() override {
        return 4 * Pi * R * R;
    }

    void PrintToFile(ofstream& outfile) override {
        outfile << "Sphere with radius: " << R << endl;
        outfile << "Volume: " << Volume() << ", Full Area: " << FullArea() << endl;
    }

    void PrintFromFile(ifstream& infile) override {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
};

class RightTriangle : public Figures {
private:
    int SideA, SideB;
public:
    RightTriangle() : SideA(3), SideB(4) {}
    RightTriangle(int sideA, int sideB) : SideA(sideA), SideB(sideB) {}

    float Area() override {
        return 0.5 * SideA * SideB;
    }

    float Perimeter() override {
        float hypotenuse = sqrt(SideA * SideA + SideB * SideB);
        return SideA + SideB + hypotenuse;
    }

    void PrintToFile(ofstream& outfile) override {
        outfile << "Right Triangle: sides = " << SideA << ", " << SideB << endl;
        outfile << "Area: " << Area() << ", Perimeter: " << Perimeter() << endl;
    }

    void PrintFromFile(ifstream& infile) override {
        string line;
        while (getline(infile, line)) {
            cout << line << endl;
        }
    }
};

void DisplayFileContent(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open file for reading!" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();
}

int main() {
    string filename = "figures_output.txt";
    int userChoice;
    string inputLine;

    while (true) { // Loop for repeated actions
        cout << "\nChoose an option:\n";
        cout << "1 - Write to file (append)\n";
        cout << "2 - Clear the file before writing\n";
        cout << "3 - Display content of the file\n";
        cout << "4 - Exit\n";
        cin >> userChoice;

        if (userChoice == 4) {
            cout << "Exiting the program...\n";
            break; // Exit the loop and terminate the program
        }

        ofstream outfile;
        if (userChoice == 1) {
            outfile.open(filename, ios::app); // Append to the end of the file
        }
        else if (userChoice == 2) {
            outfile.open(filename, ios::trunc); // Clear the file before writing

            if (!outfile.is_open()) {
                cerr << "Failed to open file for truncation!" << endl;
                continue; // Continue the loop if the file can't be opened
            }
        }
        else if (userChoice == 3) {
            // Display the file content
            DisplayFileContent(filename);
            continue; // Return to the start of the loop after displaying file content
        }
        else {
            cerr << "Invalid option selected!" << endl;
            continue; // Return to the start of the loop if an invalid choice is made
        }

        if (!outfile.is_open()) {
            cerr << "Failed to open file for writing!" << endl;
            continue; // Return to the start of the loop if file can't be opened for writing
        }

        // Ask the user which objects to write to the file
        cout << "Choose the objects to write to the file (separate choices with spaces):\n";
        cout << "1 - Parallelogram\n";
        cout << "2 - Rectangle\n";
        cout << "3 - Circle\n";
        cout << "4 - Right Triangle\n";
        cout << "5 - Cube\n";
        cout << "6 - Sphere\n";
        cout << "7 - Write all objects\n";
        cout << "Enter your choices (separate multiple choices with space): ";
        cin.ignore(); // To ignore the leftover newline from previous input
        getline(cin, inputLine); // Read the full input line
        stringstream ss(inputLine);
        int objectChoice;

        // Write objects based on the user's selection
        while (ss >> objectChoice) {
            if (objectChoice == 1) {
                Parallelogram para(3, 5, 60);
                para.PrintToFile(outfile);
            }
            else if (objectChoice == 2) {
                Rectangle rect(4, 6);
                rect.PrintToFile(outfile);
            }
            else if (objectChoice == 3) {
                Circle circle(5);
                circle.PrintToFile(outfile);
            }
            else if (objectChoice == 4) {
                RightTriangle rTri(3, 4);
                rTri.PrintToFile(outfile);
            }
            else if (objectChoice == 5) {
                Cube cube(5);
                cube.PrintToFile(outfile);
            }
            else if (objectChoice == 6) {
                Sphere sphere(3);
                sphere.PrintToFile(outfile);
            }
            else if (objectChoice == 7) {
                // Write all objects to the file
                Parallelogram para(3, 5, 60);
                Rectangle rect(4, 6);
                Circle circle(5);
                RightTriangle rTri(3, 4);
                Cube cube(5);
                Sphere sphere(3);
                para.PrintToFile(outfile);
                rect.PrintToFile(outfile);
                circle.PrintToFile(outfile);
                rTri.PrintToFile(outfile);
                cube.PrintToFile(outfile);
                sphere.PrintToFile(outfile);
            }
        }

        outfile.close();
    }

    return 0;
}
