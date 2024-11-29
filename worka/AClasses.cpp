#include <cmath> 
#include <iostream>

using namespace std;

class Equation {
public:
    virtual void solve() const = 0;
    virtual ~Equation() = default; //chat_gpt dug fix create this
};

class LinearEquation : public Equation {
private:
    double a, b; 
public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void solve() const override {
        if (a == 0) {
            cout << "The linear equation has no solutions or infinitely many solutions." << endl;
            return;
        }
        double root = -b / a; 
        cout << "Root of the linear equation: " << root << endl;
    }
};

class QuadraticEquation : public Equation {
private:
    double a, b, c;
public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() const override {
        if (a == 0) {
            LinearEquation linear(b, c);
            linear.solve();
            return;
        }

        double discriminant = b * b - 4 * a * c; // Calculate this
        if (discriminant < 0) {
            cout << "The quadratic equation has no real roots." << endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "The quadratic equation has one root: " << root << endl;
        }
        else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Roots of the quadratic equation: " << root1 << " and " << root2 << endl;
        }
    }
};

int main() {
    //liniyne rivnyanya
    LinearEquation linear(2, 3);
    linear.solve();

    QuadraticEquation quadratic(1, -4, 4);
    quadratic.solve();

    QuadraticEquation noRoots(1, 1, 1);
    noRoots.solve();

    return 0;
}
