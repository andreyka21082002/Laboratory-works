#include "XOutils.h"
#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");
	char c;
	std::cout << "Введите ваш символ (X или O или любой другой символ): " << std::endl;
	std::cin >> c;
	XO::Game game = initGame(c);
	updateDisplay(game);
	while (!updateGame(&game)) {
		updateDisplay(game);
	}

	return 0;
}
