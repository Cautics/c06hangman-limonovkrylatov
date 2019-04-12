#include <iostream>
#include <clocale>
using namespace std;

bool check(char* word, char* displayWord) {

	return false;
}


char UpCase(char c) {
	return c;
}


void chooseWord(char* buffer) {

};

int main() {
	int attempts = 9;
	char word[50], displayWord[50];
	bool success = false;
	char ch;

	setlocale(LC_ALL, "ru");
	chooseWord(word);

	while (attempts > 0 && !success) {
		cout << "Угадайте слово:\n";
		cout << displayWord << "\n";
		cout << "У вас " << attempts << "попыток\n";
		cin >> ch;
		ch = UpCase(ch);
		attempts--;
		success = check(word, displayWord);
	}
}
