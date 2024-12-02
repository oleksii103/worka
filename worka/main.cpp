#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Dictionary
{
public:
	void AddWord(string word, string translation) {
		auto it = Word.find(word);

		if (it == Word.end()) {
			Word.insert({ word, translation });
		}
	}

	void DeleteWord(string word) {
		auto it = Word.find(word);

		if (it != Word.end()) {
			Word.erase(word);
		}
	}

	void EditWord(string word, string translation) {
		auto it = Word.find(word);
		if (it == Word.end()) {
			AddWord(word, translation);
		}
		else {
			it->second = translation;
		}

	}

	friend ostream& operator <<(ostream& out, Dictionary& dictionary) {
		for_each(dictionary.Word.begin(), dictionary.Word.end(), [&out](pair <string, string> UPSO) {out << UPSO.first << " - " << UPSO.second << endl; });
		return out;
	}


private:
	map <string, string> Word;
};
int main() {
	setlocale(LC_ALL, "ukr");
	Dictionary dictionary;
	dictionary.AddWord("слово", "word");
	dictionary.AddWord("рука", "hand");
	dictionary.AddWord("джойстик", "gamepad");

	dictionary.DeleteWord("слово");

	dictionary.EditWord("джойстик", "joystick");

	cout << dictionary;
	return 0;
}