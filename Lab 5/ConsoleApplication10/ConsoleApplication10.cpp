#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct SOLD_AIR_TICKET
{
	string FLICHT_NUMBER = " ";
	string SURNAME = " ";
	string NAME = " ";
	string PASTNAME = " ";
	string DESTINATION = " ";
	int DURATION_IN_MINUTES = 0;
};

void SHOW_ALL_TICKETS(int n, SOLD_AIR_TICKET* ARRAY);

void SEARCH_SURNAME(int n, SOLD_AIR_TICKET* ARRAY);

void SORT_N_MINUTES(int n, SOLD_AIR_TICKET* ARRAY);

bool cmpByAuthor(const SOLD_AIR_TICKET& r1, const SOLD_AIR_TICKET& r2)
{
	return r1.SURNAME < r2.SURNAME;
}

int main()
{
	setlocale(LC_ALL, "");
	string x;
	SOLD_AIR_TICKET PART;
	ifstream fin;
	fin.open("F:\\file.txt");
	int n(0);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string s;
			getline(fin, s);
			n++;
		}
	}
	SOLD_AIR_TICKET* ARRAY = new SOLD_AIR_TICKET[n];
	fin.seekg(0, ios_base::beg);
	for (size_t i = 0; i < n; i++)
	{
		getline(fin, x);
		istringstream iss(x);
		iss >> PART.FLICHT_NUMBER >> PART.SURNAME >> PART.NAME >> PART.PASTNAME >> PART.DESTINATION >> PART.DURATION_IN_MINUTES;
		ARRAY[i] = PART;
	}
	cout
		<< "1. Выгрузить информацию о всех проданных билетах и вывести на экран. \n"
		<< "2. Выяснить на какие рейсы купили билеты пассажиры по фамилии Сидоров и вывести информацию о всех билетах на рейсы продолжительностью более трех часов. \n"
		<< "Выберите вариант: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		SHOW_ALL_TICKETS(n, ARRAY);
		break;
	case 2:
		SEARCH_SURNAME(n, ARRAY); SORT_N_MINUTES(n, ARRAY);
		break;
	}
	return 0;
}

void SHOW_ALL_TICKETS(int n, SOLD_AIR_TICKET* ARRAY)
{
	{
		cout << "\nНомер рейса | ФИО | Место назначения | Время полета:\n";
		for (size_t i = 0; n > i; i++)
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER
				<< " "
				<< ARRAY[i].SURNAME
				<< " "
				<< ARRAY[i].NAME
				<< " "
				<< ARRAY[i].PASTNAME
				<< " "
				<< ARRAY[i].DESTINATION
				<< " "
				<< ARRAY[i].DURATION_IN_MINUTES;
			cout << "\n\n";
		}
	}
}

void SEARCH_SURNAME(int n, SOLD_AIR_TICKET* ARRAY)
{
	cout << "\nНа какие рейсы купили билеты пассажиры по фамилии Сидоров:\n" << endl;
	for (size_t i = 0; n > i; i++)
	{
		if (!(ARRAY[i].SURNAME.find("SYDOROV")))
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER
				<< " "
				<< ARRAY[i].SURNAME
				<< " "
				<< ARRAY[i].NAME
				<< " "
				<< ARRAY[i].PASTNAME;
			cout << "\n\n";
		}
	}
}

void SORT_N_MINUTES(int n, SOLD_AIR_TICKET* ARRAY)
{
	cout << "\nИнформацию о всех билетах на рейсы продолжительностью более трех часов:\n" << endl;
	for (size_t i = 0; n > i; i++)
	{
		if (ARRAY[i].DURATION_IN_MINUTES > 180)
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER
				<< " "
				<< ARRAY[i].SURNAME
				<< " "
				<< ARRAY[i].NAME
				<< " "
				<< ARRAY[i].PASTNAME
				<< " "
				<< ARRAY[i].DESTINATION
				<< " "
				<< ARRAY[i].DURATION_IN_MINUTES; 
			cout << "\n\n";
		}
	}
}
