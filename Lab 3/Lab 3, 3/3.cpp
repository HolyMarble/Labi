#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

int main()
{
	const int a = 3;
	setlocale(LC_ALL, "");
	const char p = '\n';
	char temp_str[256];
	const int len = 41, strings = 3;
	char strng[strings][len];
	ifstream fs("F:\\file.txt");
	if (!fs) return 1; 
	for (int r = 0; r < a; r++)
	{
		fs.getline(strng[r], len - 1, p); 
	}
	cout << "Упорядоченные предложения по убыванию их длины:\n";
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			if (strlen(strng[i]) > strlen(strng[j]))
			{
				strcpy(temp_str, strng[i]);
				strcpy(strng[i], strng[j]);
				strcpy(strng[j], temp_str);
			}
	}
	for (int i = 0; i < a; i++)
		cout << endl << strng[i] << endl;
	cout << endl;
	return 0;
}
