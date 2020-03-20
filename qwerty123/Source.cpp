#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

#define stena char(178)
#define player char(40)
#define player2 char(41)
#define pysto char(0)
#define finish char(223)
#define priz char(64645414)
int i_1 = 1, j_1 = 0, level = 1;
int v, b;
	
int arr[100][100];
void input(int a) {
	ifstream f;
	switch (a)
	{
	case 1:
		f.open("E:/1.txt");
		break;
	case 2:
		f.open("E:/2.txt");
		break;
	case 3:
		f.open("E:/3.txt");
		break;
	default:
		f.close();
		exit(0);
		break;
	}
	f >> v;
	f >> b;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < b; j++)
		{
			f >> arr[i][j];
		}
	}
}
int store = 0, v1 = v, b1 = b, m = 0;
void visna(int a) {
	for (int i = 0; i < a; i++)
	{
		cout << priz << priz << " ";
	}
}
void vivod(int a) {
	if (a == 0) {
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < b; j++)
			{
				switch (arr[i][j])
				{
				case 2:
					cout << stena << stena;
					break;
				case 1:
					cout << player << player2;
					break;
				case 0:
					cout << pysto << pysto;
					break;
				case 5:
					cout << finish << finish;
					break;
				case 9:
					cout << priz << priz;
				}
			}
			cout << endl;
		}
		cout << "Store: ";
		visna(store);
	}
	else {
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < b; j++)
			{
				switch (arr[i][j])
				{
				case 2:
					cout << stena << stena;
					break;
				case 1:
					if (a == 1) {
						cout << " " << player;
					}
					if (a == 2) {
						cout << player2 << " ";
					}
					break;
				case 0:
					cout << pysto << pysto;
					break;
				case 5:
					cout << finish << finish;
					break;
				case 9:
					cout << priz << priz;
				default:
					break;
				}
			}
			cout << endl;
		}
		cout << "Store: ";
		visna(store);
		system("CLS");
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < b; j++)
			{
				switch (arr[i][j])
				{
				case 2:
					cout << stena << stena;
					break;
				case 1:
					cout << player << player2;
					break;
				case 0:
					cout << pysto << pysto;
					break;
				case 5:
					cout << finish << finish;
					break;
				case 9:
					cout << priz << priz;
				default:
					break;
				}
			}
			cout << endl;
		}
		cout << "Store: ";
		visna(store);
	}
}
void win() {
int a;
	system("CLS");
	cout << "YOU WIN!" << endl;
	cout << "Store: " << endl;
	visna(store);
	cout << "Next level?" << endl;
	cout << "YES(1)/NO(0)" << endl;
	cin >> a;
	if (a) {
		level++;
		input(level);
	}else{
		system("PAUSE");
	}
	
}
void IDIOT() {
	system("CLS");
	cout << "You DIE" << endl;
	exit(0);
}
int stoge(int i, int j) {
		if (arr[i][j] == 2) {
			return 2;
		}
		if (arr[i][j] == 5) {
			win();
		}
		if (arr[i][j] == 9) {
			store++;
		}
		return 0;
}

void maze() {
	char x;
	input();
	cout << "Ypravlenie strelockami" << endl;
	system("color 2");
	vivod(0);
	while (true) {
		x = getch();
		system("CLS");
		switch (x)
		{
		case 0:
			exit(0);
		case 72:
			up();
			break;
		case 80:
			down();
			break;
		case 75:
			left();
			break;
		case 77:
			right();
			break;
		default:
			break;
		}
	}
}
int main() {
	setlocale(LC_ALL, ".866");
	maze();

}
