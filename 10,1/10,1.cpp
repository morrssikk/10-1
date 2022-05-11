#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do {
		cin.get();
		cin.sync();
		cout << " Ввести рядок: "; getline(cin, s);
		fout << s << endl;
		cout << "Продовжити? (y/n) "; cin >> ch;
	}
	while (ch == 'y' || ch == 'Y');
			cout << endl;

}
	


void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
}

int ProcessTXT(char* fname)
{
	ifstream fin(fname);
	string s; 
	int count = 0;

	while (getline(fin, s)) {
		for (int i = 0; i < s.length(); i++) {
			const int firstLetterIsValid = s[i] == 'a' || s[i] == 'b' || s[i] == 'c';
			const int secondLetterIsValid = s[i + 1] == 'a' || s[i + 1] == 'b' || s[i + 1] == 'c';
			const int thirdLetterIsValid = s[i + 2] == 'a' || s[i + 2] == 'b' || s[i + 2] == 'c';
			if (firstLetterIsValid && secondLetterIsValid && thirdLetterIsValid) {
				count++;
				i += 2;
			}
		}
	}
	return count;
}


int main()
{
	SetConsoleCP(1251);
SetConsoleOutputCP(1251);
char fname[100];
cout << "Ввести ім'я файлу: "; cin >> fname;

CreateTXT(fname);
PrintTXT(fname);

cout << "кількість входжень: " << ProcessTXT(fname) << endl;

return 0;
}
