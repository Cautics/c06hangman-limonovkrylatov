#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

bool check(char* word, char* displayWord,int length,char ch) {
	int a = 0;
	for (int i = 0;i < length;i++) {
		
		if (ch == word[i]) {
			displayWord[i] = word[i];
			a = 1;
		}
	}
	if (a == 0) return false;
	else return true;
}


char UpCase(char c) {
	if (c >= 'А'&&c <= 'Я')
		c += 32;
	return c;
}


void chooseWord(char* buffer){
	srand(time(0));
	int numword = rand() % 1001;
	ifstream our_dict("dictionary.txt");

	system("chcp 1251>>null");

	
	//писать цикл для считывания numword - того слова в  buffer
	for (int i=0;i<numword;i++)
	our_dict >> buffer;
	//cout << buffer << endl;
	
};

int main() {
	int attempts = 9,length=0,slash=0;
	char word[50];
	chooseWord(word);
	length = strlen(word);
	char* displayWord=new char [length];
	bool success = false, mistake = false,end=false;
	char ch;
	for (int i = 0;i < length;i++)
		displayWord[i] = '_';
    setlocale(LC_ALL, "ru");
	
	

	while (attempts > 0 && !end) {
		cout << "Угадай слово\n";
		for (int i = 0;i < length;i++)
			cout << displayWord[i] << ' ';
		cout << endl;
		cout << "У вас " << attempts << " попыток\n";
		cin >> ch;
		ch = UpCase(ch);
		// cout <<(ch == word[2]); 
		success = check(word, displayWord,length,ch);
		if (success == false)
			attempts--;
		for (int i = 0;i < length;i++) {
			if (displayWord[i] != '_') {
				slash++;
			}
			else break;
		}
		if (slash == length) { 
			for (int i = 0;i < length;i++)
				cout << displayWord[i];
			cout << endl;
			cout << "You are poliglot \nyou are so beautiful call me ";
			end = true; }
		else slash = 0;
		if (attempts == 0) cout <<"This word you need to learn: "<<word <<"\n"<< "You are sausage!try again sausage.";
	}
}
