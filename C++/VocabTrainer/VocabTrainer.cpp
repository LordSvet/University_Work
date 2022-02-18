#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/// <summary>
/// Created class Word to help me with organizing the words
/// </summary>
class Word {
private: 
	string original;
	string translated;
public:
	Word(string original, string translated) {
		this->original = original;
		this->translated = translated;
	}

	void setOriginal(string original) {
		this->original = original;
	}
	void setTranslated(string translated) {
		this->translated = translated;
	}
	string getOriginal() {
		return original;
	}
	string getTranslated() {
		return translated;
	}

};

/// <summary>
/// Main method where first I have inserted in a vector of type Word a few initial words and they are then insterted in a multimap.
/// Then the user can input different options to the console including adding a new word, trying to translate a random word from one of the
/// languages or just get a random word and its translation.
/// </summary>
/// <returns></returns>
int main() {
	int randomIndex;
	bool loop = true;
	string origin;
	string translation;
	multimap<string, string> dictionary;	//Using multimap as it allows duplicated values as some words have different meanings
	vector<Word*> wordVector;
	wordVector.push_back(new Word("Phone","Handy"));
	wordVector.push_back(new Word("Car","Auto"));
	wordVector.push_back(new Word("Pallet Truck","Hubwagen"));
	wordVector.push_back(new Word("play","spielen"));
	wordVector.push_back(new Word("Apple","Apfel"));
	wordVector.push_back(new Word("think","denken"));
	wordVector.push_back(new Word("think","glauben"));
	wordVector.push_back(new Word("think","meinen"));
	wordVector.push_back(new Word("Glass","Glas"));
	wordVector.push_back(new Word("Picture","Bild"));
	wordVector.push_back(new Word("Picture","Foto"));
	wordVector.push_back(new Word("Penguin","Pinguin"));
	wordVector.push_back(new Word("Vocabulary","Wortschatz"));

	for (int i = 0; i < wordVector.size(); i++) {
		dictionary.insert(make_pair(wordVector[i]->getOriginal(), wordVector[i]->getTranslated()));
	}
	auto it{dictionary.begin()};

	cout << "Welcome to the English-German vocab trainer!\n\n";
	while (loop) {
		cout << "1.Enter new words\n";
		cout << "2.Try translating words from English\n";
		cout << "3.Try translating words from German\n";
		cout << "4.Get random word and translation\n";
		cout << "5.Exit";
		int i{};
		cout << "\nPlease enter one of numbers:";
		cin >> i;

		switch (i) {

		case 1:
			cout << "Enter word in English: ";
			cin >> origin;
			cout << "Enter word in German: ";
			cin >> translation;
			wordVector.push_back(new Word(origin,translation));
			dictionary.insert(make_pair(origin, translation));
			cout << "Words added!\n\n";
			break;
		case 2:
			 randomIndex = rand() % wordVector.size();
			cout << "\n\nTranslate " << wordVector[randomIndex]->getOriginal() << " to German:";
			cin >> translation;
			if (translation == wordVector[randomIndex]->getTranslated()) {
				cout << "\nCorrect!" << endl;
			}
			else cout << "Incorrect :(, correct answer is " << wordVector[randomIndex]->getTranslated() << endl;
			break;
		case 3:
			 randomIndex = rand() % wordVector.size();
			cout << "\n\nTranslate " << wordVector[randomIndex]->getTranslated() << " to English:";
			cin >> origin;
			if (origin == wordVector[randomIndex]->getOriginal()) {
				cout << "\nCorrect!" << endl;
			}
			else cout << "Incorrect :(, correct answer is " << wordVector[randomIndex]->getOriginal() << endl;
			break;
		case 4:
			 randomIndex = rand() % wordVector.size();
			cout << "\nRandom word in English and then translated to German: " << wordVector[randomIndex]->getOriginal()
				 << " - " << wordVector[randomIndex]->getTranslated() << endl << endl;
			break;
		case 5:
			loop = false;
			break;
		default:
			cout << "Please re-enter one of the numbers above!\n";
			break;
		}
	}

}
