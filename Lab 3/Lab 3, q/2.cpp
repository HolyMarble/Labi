#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

namespace SecondTask
{
	void FindTheShortestWord(char* MainStr, int min, char* BeforeChangesStr)
	{
		cout << MainStr;
		for (char* p = strtok(MainStr, " "); p; p = strtok(NULL, " "))
		{
			if (strlen(p) < min)
			{
				min = strlen(p);
				strcpy(BeforeChangesStr, p);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "");
	int min = 25;
	char MainStr[100];
	char BeforeChangesStr[100];
	char AllFileInOneArray[3][41];
	const char p = '\n';
	string path = "F:\\file.txt";
	ifstream fin;
	fin.open(path);
	for (int i = 0; i < 3; i++)
	{
		fin.getline(AllFileInOneArray[i], 41 - 1, p);
		cout << AllFileInOneArray[i] << "\n";
	}
	cout << endl;
	strcpy(MainStr, AllFileInOneArray[0]);
	SecondTask::FindTheShortestWord(MainStr, min, BeforeChangesStr);
	cout << endl << "Самое короткое слово в строке: " << BeforeChangesStr;
	return 0;
}

