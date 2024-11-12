#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

//figure code copy-paste from 02.11.2024
using namespace std;

const float Pi = 3.141592653589793;

class Figures {
public:
    friend ostream& operator<<(ostream& out, Figures& figure) {
        out << "I am a figure. ";
        return out;
    }
    virtual float Area() = 0;
    virtual float Perimeter() = 0;
    virtual ~Figures() {}
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
    friend ostream& operator<<(ostream& out, Parallelogram& para) {
        out << "Parallelogram: " << para.SideA << ", " << para.SideB << ", " << para.Angle << " degrees.";
        return out;
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle() : Parallelogram(1, 2, 90) {}
    Rectangle(int sideA, int sideB) : Parallelogram(sideA, sideB, 90) {}

    friend ostream& operator<<(ostream& out, Rectangle& rect) {
        out << "Rectangle: " << rect.SideA << " x " << rect.SideB;
        return out;
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
    friend ostream& operator<<(ostream& out, Circle& circle) {
        out << "Circle with radius: " << circle.R;
        return out;
    }
};

class D3Figure {
public:
    virtual double Volume() = 0;
    virtual double FullArea() = 0;
    virtual ~D3Figure() {}
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

    friend ostream& operator<<(ostream& out, Cube& cube) {
        out << "Cube with side: " << cube.Side;
        return out;
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

    friend ostream& operator<<(ostream& out, Sphere& sphere) {
        out << "Sphere with radius: " << sphere.R;
        return out;
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

    friend ostream& operator<<(ostream& out, RightTriangle& tri) {
        out << "Right Triangle: sides = " << tri.SideA << ", " << tri.SideB;
        return out;
    }
};

int main() {
    string filename = "figures_output.txt";

    //user interface
    int userChoice;
    cout << "Choose an option:\n";
    cout << "1 - Write to file (append)\n";
    cout << "2 - Clear the file before writing\n";
    cin >> userChoice;

    //chat gpt work whis file "add to file" "clear file" (it`s doesn`t work) 
    ofstream outfile;
    if (userChoice == '1') {
        outfile.open(filename, ios::app); 
    }
    else if (userChoice == '2') {
        outfile.open(filename, ios::trunc); 
    }

    //wtf are you want you can use only 1 or 2 
    else {
        cerr << "Invalid option selected!" << endl;
        return 1;
    }

    //can`t open 
    if (!outfile.is_open()) {
        cerr << "Failed to open file for writing!" << endl;
        return 1;
    }

    //create objects
    Parallelogram para(3, 5, 60);
    Rectangle rect(4, 6);
    Circle circle(5);
    RightTriangle rTri(3, 4);
    Cube cube(5);
    Sphere sphere(3);

    //data output
    outfile << para << endl;
    outfile << "Area: " << para.Area() << ", Perimeter: " << para.Perimeter() << endl;

    outfile << rect << endl;

    outfile << circle << endl;
    outfile << "Area: " << circle.Area() << ", Perimeter: " << circle.Perimeter() << endl;

    outfile << rTri << endl;

    outfile << cube << endl;
    outfile << "Volume: " << cube.Volume() << ", Full Area: " << cube.FullArea() << endl;

    outfile << sphere << endl;
    outfile << "Volume: " << sphere.Volume() << ", Full Area: " << sphere.FullArea() << endl;

    outfile.close();

    //success 
    cout << "Data successfully written to file \"" << filename << "\"." << endl;

    return 0;
}
