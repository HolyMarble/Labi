#include <iostream>

using namespace std;

void area_scan(char** area);
void player(char** area);
void computer(char** area);
char winner(char** area);

int main()
{
	setlocale(LC_ALL, "Russian");
	char round;
	round = ' ';
	char** area;
	area = new char* [3];
	for (int i = 0; i < 3; i++)
		area[i] = new char[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			area[i][j] = ' ';
	do
	{
		area_scan(area);
		player(area);
		round = winner(area);
		if (round != ' ')
			break;
		computer(area);
		round = winner(area);
	} while (round == ' ');
	if (round == 'X')
		cout << "Победил игрок!\n";
	else
		cout << "Победил компьютер!\n";
	area_scan(area);
	return 0;
}

void area_scan(char** area)
{
	for (int i = 0; i < 3; i++)
	{
		cout << area[i][0] << " | " << area[i][1] << " | " << area[i][2];
		if (i != 2) cout << "\n \n";
	}
	cout << endl;
}

void player(char** area)
{
	int x, y;
	cout << "Выберите строку: "; cin >> x;
	cout << "Выбирите столбец: "; cin >> y;
	x--; y--;
	if (x < 0 || y < 0 || x>2 || y>2 || area[x][y] != ' ')
	{
		cout << "Неверный выбор, попробуйте еще раз.\n";
		player(area);
	}
	else area[x][y] = 'X';
}

void computer(char** area)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (area[i][j] == ' ') break;
		if (area[i][j] == ' ') break;
	}
	if (i * j == 9)
	{
		cout << "Вы проиграли!\n";
		exit(0);
	}
	else
		area[i][j] = 'O';
}

char winner(char** area)
{
	int i;
	for (i = 0; i < 3; i++)
		if (area[i][0] == area[i][1] && area[i][0] == area[i][2])
			return area[i][0];
	for (i = 0; i < 3; i++)
		if (area[0][i] == area[1][i] && area[0][i] == area[2][i])
			return area[0][i];
	if (area[0][0] == area[1][1] && area[1][1] == area[2][2])
		return area[0][0];
	if (area[0][2] == area[1][1] && area[1][1] == area[2][0])
		return area[0][2];
	return ' ';
}

