// XO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "XOutils.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char c;
	cout << "Введите ваш символ (X или O или любой другой символ): " << std::endl;
	cin >> c;
	XO::Game game = initGame(c);
	updateDisplay(game);
	while (!updateGame(&game)) {
		updateDisplay(game);
	}

	return 0;
}
