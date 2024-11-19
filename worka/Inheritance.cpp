#include <iostream>
#include <string> 
using namespace std;

class Pet
{
protected:
	int Age; //pet`s age 
	string Name; //pet`s name
	string Breed; //poroda of the pet 

public:
	Pet(string name, int age, string breed ) : Age(age), Name(name), Breed(breed){}

	virtual string Sound() const=0;

	void Display() const {
		cout << Name << ", " << Age << " Years old, Breed: " << Breed << endl;
	}

	virtual ~Pet() {}
};

class Dog : public Pet
{
public:
	Dog(const string& name, int age, const string& breed) : Pet(name, age, breed) {}

	string Sound() const override { //whis gpt help but must working
		return "bark";  //American dog sound 
	}
};

class Cat : public Pet {
public:
	Cat(const string& name, int age, const string& breed) : Pet(name, age, breed) {}

	string Sound() const override {
		return "nya"; //Japanese cat-girl sound  
	}
};

class Parrot : public Pet {
public:
	Parrot(const string& name, int age, const string& breed) : Pet(name, age, breed){}

	string Sound() const override {
		return "give me your bread"; //Ua dove sound  
	}
};

int main() {
	Dog dog("Misha", 5, "Dachshund");
	Cat cat("Vasya", 3, "Sphinx");
	Parrot parrot("Grisha", 2, "Corella");

	dog.Display();
	cout << "Sound: " << dog.Sound() << endl;

	cat.Display();
	cout << "Sound: " << cat.Sound() << endl;

	parrot.Display();
	cout << "Sound: " << parrot.Sound() << endl;

	return 0;
};

