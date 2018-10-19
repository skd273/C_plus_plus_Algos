#include <iostream>
#include <Windows.h>
#include <time.h>

/*
	On the chessboard there are N figures of the opponent. 
	Place on it the minimum number of bishops so that all the 
	enemy pieces are “under attack”.
*/

int m[8][8];// { // 0 - empty, 5 - enemy, 4 - bishop, 9 - under attack

void randMy(int n) {
	int a=0, b=0, q=0, i=0, j= 0;
	for (i = 0, j = 0; i < 8; i++) {
		for (; j < 8; j++) {
			m[i][j] = 0;
		}
	}
	while (q != n) {
		a = rand() % 7 - 0;
		b = rand() % 7 - 0;
		if (m[a][b] != 5) {
			m[a][b] = 5; q++;
		}
	}
}

int mDone[8][8] = {
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 }
};

void printM() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (m[i][j]==6) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 2));
			if (m[i][j] == 5) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 4));
			std::cout << m[i][j] << ' ';
			if (m[i][j] == 6) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));
			if (m[i][j] == 5) SetConsoleTextAttribute(hConsole, (WORD)((0 << 3) | 15));
		}
		std::cout << std::endl;
	}

	
}

void markPlace(int x, int y, int q) {
	int dx = 1, dy = 1; // q == 1 
	if (q == 2) {dx = -1; dy = -1;}
	if (q == 3) {dy = -1; }
	if (q == 1) dx = -1;
	if ((x + dx < 8) && (x + dx >= 0) && (y + dy < 8) && (y + dy >= 0)) {
		if ((m[x + dx][y + dy] != 5)) m[x + dx][y + dy]++;
		markPlace(x + dx, y + dy, q);
	}
}

void placeBishops(int x, int y, int q, int Bishop[]) {
	int dx = 1, dy = 1; // q == 1 
	if (q == 2) { dx = -1; dy = -1; }
	if (q == 3) { dy = -1; }
	if (q == 1) dx = -1;
	if ((x + dx < 8) && (x + dx >= 0) && (y + dy < 8) && (y + dy >= 0)) {
		if (m[x + dx][y + dy] > Bishop[0] && (m[x + dx][y + dy] != 5)) {
			Bishop[0] = m[x + dx][y + dy]; Bishop[1] = x + dx; Bishop[2] = y + dy;
		}
		placeBishops(x + dx, y + dy, q, Bishop);
	}
}

void findPlace(int x, int y) {
	int Bishop[3] = { -1, 0, 0 }; // max, x, y
	placeBishops(x, y, 1, Bishop);
	placeBishops(x, y, 2, Bishop);
	placeBishops(x, y, 3, Bishop);
	placeBishops(x, y, 4, Bishop);
	m[Bishop[1]][Bishop[2]] = 6;
}

void find(int x, int y) {
	markPlace(x, y, 1);
	markPlace(x, y, 2);
	markPlace(x, y, 3);
	markPlace(x, y, 4);
}

void search() {
	int exit = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (m[i][j] == 5) find(i, j);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if (m[i][j] == 5) findPlace(i, j);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			if ((m[i][j] != 5)&&(m[i][j] != 6)) m[i][j] = 0;
	}
}

void main() {
	srand(time(0));
	int n;
	std::cin >> n;
	randMy(n);
	printM();
	search();
	system("pause");
	printM();
	system("pause");
}