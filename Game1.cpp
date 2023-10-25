#include <iostream>
using namespace std;

char board[3][3]; // Массив для поля.

void print_board() { // Функция для отображения поля.
	system("cls");
	cout << "  1 2 3\n";
	for (int i = 0; i < 3; ++i) {
		cout << i + 1 << ' ';
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl << endl << endl;
	return;
}

int main()
{

	for (int i = 0; i < 3; ++i) { // Создали поле 3 на 3 с помощью нижних слешев.
		for (int j = 0; j < 3; ++j) {
			board[i][j] = '_';
		}
  }
	for (int h = 0; h < 9; h++) { // Обозначили максимальное количество ходов, ввели очередность игроков и символы их действий.
		char sign;
		if (h % 2 == 0) sign = 'X';
		else sign = 'O';
		while (true) {
			print_board();
			cout << ((h % 2 == 0) ? "Hod igroka 1 " : "Hod igroka 2");
			cout << "\nVvedite coordinaty:	";
			int x, y; 
			cin >> x >> y;
			--x, --y;
			if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == '_') { // Ограничения для пользователя
				board[x][y] = sign;							
				break;
			}
		}
		bool is_row = false; // Условия победы.
		for (int i = 0; i < 3; ++i) { // По строкам.
			bool fl = true;
			for (int j = 0; j < 3; ++j) {
				if (board[i][j] != sign) fl = false;
			}
			is_row |= fl;
		}
		bool is_col = false; // Условие по столбам.
		for (int i = 0; i < 3; ++i) {
			bool fl = true;
			for (int j = 0; j < 3; ++j) {
				if (board[j][i] != sign) fl = false;
			}
			is_col |= fl;
		}
		bool is_diag = false; // Условие по главной диагонали.
		bool fl = true;
		for (int i = 0; i < 3; ++i) {
			if (board[i][i]) fl = false;
		}
		is_diag |= fl;
		fl = true; // Условие по побочной диагонали.
		for (int i = 0; i < 3; ++i) {
			if (board[i][2 - i] != sign) fl = false;
		}
		is_diag |= fl;
		if (is_row || is_col || is_diag) {
			print_board();
			cout << ((h % 2 == 0) ? "Igrok 1 pobedil\n" : "Igrok 2 pobedi;\n");
			cout << endl;
			return 0;
		}
	}
	print_board(); // Вывод результата ничьей.
	cout << endl << "Draw" << endl;
}
