#include <iostream>
#include <string>
#include "Menu.h"

Menu::Menu()
{
	menuLength = 6;
	menuList = new std::string[]{
		" - Добавить дело",
		" - Удалить дело",
		" - Редактировать дело",
		" - Поиск дела",
		" - Отображение списка дел",
		" - Выход"
	};
}

void Menu::show(bool isLongMenu)
{
	std::cout << "\n\t<<< Меню: >>>\n\n";

	if (isLongMenu)
		for (int i = 0; i < menuLength; ++i)
			std::cout << i + 1 << ' ' << *(menuList + i) << std::endl;
	else
	{
		std::cout << 1 << ' ' << *(menuList) << std::endl;
		std::cout << 2 << ' ' << *(menuList + menuLength - 1) << std::endl;
	}
}

int Menu::getSelect(bool isLongMenu)
{
	std::cout << "\nВаш выбор: ";
	std::string select;
	int selected = -1;
	while (1)
	{
		getline(std::cin, select);
		int pos = select.find_first_of("0123456789");
		if (pos >= 0)
		{
			selected = select[pos] - '0';
			if (selected > 0 &&
				isLongMenu &&
				selected <= menuLength ||
				selected == 1 ||
				selected == 2)
				break;
		}

		std::cout << "Ошибочный выбор. Повторите...\n-->";
	}

	if (selected == menuLength &&
		isLongMenu ||
		selected == 2 &&
		!isLongMenu)
	{
		system("cls");
		std::cout << "\nОсуществляется выход...\n";
		exit(100);
	}

	return selected;
}