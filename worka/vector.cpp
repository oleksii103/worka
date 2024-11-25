#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Output {
public:
	void operator() (T elem) const {
		cout << elem << endl;
	}    
};

class PSP {
private:
	string Model;  
	int Storage;

public:
	PSP(string M, int S) : Model(M), Storage(S) {}

	friend ostream& operator << (ostream& out, PSP& psp) {
		out << "Heil i`m psp model: " << psp.Model << " and storage: " << psp.Storage << endl;
		return out;
	}
	bool operator > (PSP& NotFirst) {
		vector<string> order = { "psp3000", "psp2000", "psp1000", "pspStreet" };

		auto thisIndex = find(order.begin(), order.end(), this->Model);
		auto otherIndex = find(order.begin(), order.end(), NotFirst.Model);

		if (thisIndex == otherIndex) {
			return  this->Storage > NotFirst.Storage;
		}
		return thisIndex < otherIndex; 
	}


	void displayInfo() const {
		cout << "Model: " << Model << ", Storage: " << Storage << " ца" << endl;
	}
};

bool ConsoleFilter(PSP First, PSP NotFirst) {
	return First > NotFirst;
}


bool UDgreater(int elem1, int elem2)
{
	return elem1 > elem2;
}
int main() {
	vector <int> MrVector = {16, 15, 9, 34, 7, 87, 43};

	vector<int>::iterator itBegin = MrVector.begin();
	vector<int>::iterator itEnd = MrVector.end();

	cout << "non sorted vector: " << endl;
	for_each(itBegin, itEnd, Output <int>());
	cout << endl;

	vector<PSP> Console = { PSP("pspStreet", 4), PSP("psp3000", 32), PSP("psp2000", 16), PSP("psp1000", 8), PSP("psp3000", 8), PSP("pspStreet", 64) };

	vector<PSP>::iterator ItBegin = Console.begin();
	vector<PSP>::iterator ItEnd = Console.end();

	cout << "non sorted vector whis PSP: " << endl;
	for_each(ItBegin, ItEnd, Output <PSP>());

	sort(ItBegin, ItEnd, ConsoleFilter);
	cout << "sorted vector: " << endl;
	for_each(ItBegin, ItEnd, Output <PSP>());

	return 0;
}
