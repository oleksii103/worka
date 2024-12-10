#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class City {
	string name;
	string mayor;
public:
	City(string name, string mayor) {
		this->name = name;
		this->mayor = mayor;
	}

	friend ostream& operator<<(ostream& out, City copy) {
		out << "City`s name:" << copy.name << "\nMayor:" << copy.mayor << endl;
		return out;
	}

	friend ofstream& operator<<(ofstream& out, City& copy) {
		out << copy.name << ';' << copy.mayor << ':';
		return out;
	}
};

class Country {
	string name;
	string president;
	vector<City> cities;
public:
	Country(string name, string president) {
		this->name = name;
		this->president = president;
	}

	string getName() {
		return name;
	}

	vector<City>& GetCities() {
		return this->cities;
	}

	friend ostream& operator<<(ostream& out, Country& copy) {
		out << "Country`s name:" << copy.name << "\nPresident:" << copy.president << endl;
		out << "Cities:\n";
		for_each(copy.cities.begin(), copy.cities.end(), [&out](City city) {out << city << endl; });
		return out;
	}

	friend ofstream& operator<<(ofstream& out, Country& copy) {
		out << copy.name << ';' << copy.president << ';';
		for_each(copy.cities.begin(), copy.cities.end(), [&out](City& city) {out << city; });
		return out;
	}
};


void FindCity(vector<Country>& Countries) {
	string countryName;
	cout << "enter the country name" << endl;
	cin >> countryName;
	find_if(Countries.begin(), Countries.end(), [&countryName](Country& elem) {
		int a;
		bool a = true;
		if ()
		});
	
}

void ChangeName(vector<string>) {
	string county;
	cout << "Which city you`d like to change?";
	cin >> county;

}

void AddCityOrCounry() {
	int a;
	bool b;
	cout << "what 1.countre or 2.city you want?" << endl;
	cin >> a;
	string c;
	if (a == 1) {
		b = true;
		cout << "enter countre name" << endl;
		cin >> c;
	}
	else {
		b = false;
		cout << "enter city name" << endl;
		cin >> c;
	}
}

void DisplayCounties() {


}

void DisplayCities() {
	string county;
	cout << "Which counry you`d like to see?";
	cin >> county;

}

void NumberOfCities(vector<string>) {
	string county;
	cout << "Which counry`s number of cities you`d like to see?";
	cin >> county;
}

void Delete(vector<string>) {
	string name;
	int countyOrCity;
	bool choice;
	cout << "Which 1.counry or 2.city you`d like to delete?";
	cin >> countyOrCity;
	if (countyOrCity == 1)
	{
		choice = true;
		cout << "Enter county name:";
		cin >> name;


	}
	else if (countyOrCity == 2)
	{
		choice = false;
		cout << "Enter city name:";
		cin >> name;

	}
	else
	{
		return;
	}
}

void readFromFile(string filepath, vector<Country>& Countries) {
	string line;
	fstream file(filepath);

	while (getline(file, line))
	{
		int pos = line.find(';'); //ЎукаЇмо першу ";"
		string name = line.substr(0, pos); //«бер≥гаЇмо частину тексту в≥д початку до ";"
		line.erase(0, pos + 1); //¬идал€Їмо збережений р€док з початкового тексту

		pos = line.find(';');
		string president = line.substr(0, pos);
		line.erase(0, pos + 1);

		Country tmpCo(name, president);


		while (line.find(':') != string::npos)
		{

			pos = line.find(';');
			string city = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(':');
			string mayor = line.substr(0, pos);
			line.erase(0, pos + 1);

			City tmpCi(city, mayor);

			tmpCo.GetCities().push_back(tmpCi);
		}

		Countries.push_back(tmpCo);

	}
	file.close();
}

void writeToFile(string filepath, vector<Country>& Countries) {
	ofstream file(filepath, 'w');

	for_each(Countries.begin(), Countries.end(), [&file](Country counrty) {file << counrty << endl; });

	file.close();
}

int main()
{
	string filepath = "text.txt";
	vector<Country> Countries;

	readFromFile(filepath, Countries);

	for_each(Countries.begin(), Countries.end(), [](Country country) {cout << country << endl; });


	writeToFile(filepath, Countries);


	cout << "STL\nList of cities" << endl;
	int choice;
	cout << "|1. Find city            |" << endl;//-
	cout << "|2. Change cities name   |" << endl;//+
	cout << "|3. Add city or counry   |" << endl;//+
	cout << "|4. Delete city or counry|" << endl;//+
	cout << "|5. Number of cities     |" << endl;//+
	cout << "|6. Display counries     |" << endl;//-
	cout << "|7. Display cities       |\n|   of one counry        |" << endl;//+
	cout << "|0. Exit                 |" << endl;
	cin >> choice;
	while (true)
	{
		switch (choice) {
		case 1:
			FindCity();
			break;

		case 2:
			//ChangeName(vector<string>);
			break;

		case 3:
			AddCityOrCounry();
			break;

		case 4:
			//Delete();

			break;

		case 5:
			//NumberOfCities(vector<string>);
			break;

		case 6:
			DisplayCounties();
			break;


		case 7:
			DisplayCities();
			break;

		case 0:
			return 0;
			break;

		default:
			break;
		}
	}

}