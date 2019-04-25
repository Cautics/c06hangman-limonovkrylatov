#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

bool check(char* word, char* displayWord) {

	return false;
}


char UpCase(char c) {
	return c;
}


void chooseWord(char* buffer) {
	srand(time(0));
	int numword = rand() % 1001;
	ifstream our_dict("dictionary.txt");
	
	//писать цикл для считывания numword - того слова в  buffer
	our_dict >> buffer;
	cout << buffer;
	
};

int main() {
	int attempts = 9;
	char word[50], displayWord[50];
	bool success = false;
	
	char ch;

    setlocale(LC_ALL, "ru");
	//system("chcp 1251");
	
	chooseWord(word);

	while (attempts > 0 && !success) {
		cout << "Угадай слово\n";
		cout << displayWord << "\n";
		cout << "У вас " << attempts << " попыток\n";
		cin >> ch;
		ch = UpCase(ch);
		// cout <<(ch == word[2]);
		attempts--; 
		success = check(word, displayWord);
	}
}
