#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Interface.h"
#include "field.h"
#include "players.h"
#include "Game.h"

const std::string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[40];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d:%X", &tstruct);
	std::string path = buf;
	path.append(".txt");
	return path;
}

int main()

{

	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int k = 0;
	std::cout << "\tSRU.L.K.E.R. Call of toilet\n"
		"\t\t*Дисклеймер*\n"
		"Данная игра не хочет задеть чьих-то чувств.\n"
		"Все события являются вымышленными, совпадения случайны.\n"
		"Игра может вызывать эпилепсию. Проконсультируйтеть с врачами. Если противопоказано, то следует выйти из игры.\n"
		"Игра может вызывать рвотный рефлекс. Проконсультируйтеть с врачами. Если противопоказано, то следует ничего не есть за 8 часов до игры.\n"
		"Игра может вызывать чувство, что вас обманули, что это игра. Проконсультируйтеть с программистами.\n";
	std::cout <<
		"\t1 - Новая игра\n"
		"\t2 - Загрузить игру\n"
		"\t3 - Выйти из игры\n";
	std::cin >> k;
	if (k == 1 || k == 2) {
		Game game;
		std::string path;

		switch (k)
		{
		case 1:
			game.RenderGame();
			break;
		case 2:
			std::cout << "Введите путь до сохранения: ";
			std::cin >> path;
			game.LoadGame(path);
			game.RenderGame();
		case 3:
		default:
			game.GameOver();
			break;
		}
	}
	
	std::cout << "Конец!\n";
	system("pause");
	return 0;

}