#include <iostream>
#include <cstring>
#include "mystring.h"

using namespace std;


/// <summary>
/// Implementing all functions both member and non-member under 
/// namespace stringexercise.
/// </summary>
namespace stringexercise {

	mystring::mystring(){
		capacity = 1;
		occupied = 1;
		sequence = new char[capacity];
	}

	mystring::mystring(const char str[]) {
		capacity = strlen(str);
		occupied = capacity;
		sequence = new char[capacity];
		strcpy(sequence, str);
	}

	mystring::mystring(const std::string str) {
		capacity = sizeof(str);
		occupied = capacity;
		sequence = new char[capacity];
		
		for (int i = 0; i < capacity; i++) {
			sequence[i] = str[i];
		}
	}
	mystring::mystring(const mystring& source) {
		capacity = source.capacity;
		occupied = source.occupied;
		sequence = new char[capacity];
		strcpy(sequence, source.sequence);
	}
	mystring::~mystring() {
	}

	mystring& mystring::operator+=(const mystring& addend) {
		capacity += addend.occupied;
		for (int i = 0; i < addend.length(); i++) {
			sequence[occupied] = addend[i];
			occupied++;
		}
		return *this;
	}
	mystring& mystring::operator+=(const char addend[]) {
		capacity += strlen(addend);
		for (int i = 0; i < strlen(addend); i++) {
			sequence[occupied] = addend[i];
			occupied++;
		}
		return *this;
	}
	mystring& mystring::operator+=(const char addend) {
		capacity++;
		sequence += addend;
		occupied++;
		return *this;
	}

	mystring& mystring::operator=(const mystring& addend) {
		capacity = addend.capacity;
		occupied = addend.occupied;
		sequence = new char[capacity];
		strcpy(sequence, addend.sequence);
		return *this;
	}

	const char& mystring::operator[](size_t position) const {
		return sequence[position];
	}
	char& mystring::operator[](size_t position) {
		return sequence[position];
	}

	void mystring::swap(mystring& ms1){
		mystring mscopy(ms1);
		ms1.capacity = capacity;
		ms1.occupied = occupied;
		for (int i = 0; i < capacity; i++) {
			ms1.sequence[i] = sequence[i];
		}
		capacity = mscopy.capacity;
		occupied = mscopy.occupied;
		for (int i = 0; i < capacity; i++) {
			sequence[i] = mscopy.sequence[i];
		}
	}

	std::ostream& operator <<(std::ostream& outs, const mystring& source) {
		for (int i = 0; i < source.length(); i++) {
			outs << source[i];
		}
		return outs;
	}

	std::istream& operator>>(std::istream& ins, mystring& target){
		char word[sizeof(target)];
		ins >> word;
		target = word;
		return ins;
	}

	mystring operator+(const mystring& s1, const mystring& s2) {
		mystring ms1(s1);
		for (size_t i = s1.length(); i < s1.length() + s2.length(); i++) {
			ms1 += s2[i];
		}
		return ms1;
	}
	mystring operator+(const mystring& s1, const char* s2) {
		mystring ms1(s1);
		ms1 += s2;
		return ms1;
	}
	mystring operator+(const char* s1, const mystring& s2) {
		mystring ms1(s1);
		ms1 += s2;
		return ms1;
		return ms1;
	}

	bool operator==(const mystring& s1, const mystring& s2) {
		if (s1.length() == s2.length()) {
			return true;
		}
		else
			return false;
	}
	bool operator!=(const mystring& s1, const mystring& s2) {
		if (s1.length() != s2.length()) {
			return true;
		}
		else
			return false;
	}
	bool operator>=(const mystring& s1, const mystring& s2) {
		if (s1.length() >= s2.length()) {
			return true;
		}
		else
			return false;
	}
	bool operator<=(const mystring& s1, const mystring& s2) {
		if (s1.length() <= s2.length()) {
			return true;
		}
		else
			return false;
	}
	bool operator> (const mystring& s1, const mystring& s2) {
		if (s1.length() > s2.length()) {
			return true;
		}
		else
			return false;
	}
	bool operator< (const mystring& s1, const mystring& s2) {
		if (s1.length() < s2.length()) {
			return true;
		}
		else
			return false;
	}
}

/// <summary>
/// Main method for testing.
/// </summary>
/// <returns></returns>
int main() {

	char baba[] = "babati";

	stringexercise::mystring dqdo(baba);
	stringexercise::mystring lelq(dqdo);

	dqdo += lelq;
	dqdo += "a";
	lelq = dqdo;

	cin >> dqdo; 

	cout << dqdo << endl;
	cout << lelq << endl;

	dqdo.swap(lelq);

	cout << dqdo << endl;
	cout << lelq << endl;

	return 0;
}