#include <iostream>
#include <string>
#include <vector>
#include "TodoList.h"
#include "Menu.h"

void Menu::show(bool isLongMenu, std::vector <std::string> menuList)
{
	if (isLongMenu)
		for (int i = 0; i < menuList.size(); ++i)
			std::cout << ' ' << i + 1 << ' ' << menuList.at(i) << std::endl;
	else
	{
		std::cout << ' ' << 1 << ' ' << menuList.at(0) << std::endl;
		std::cout << ' ' << 2 << ' ' << menuList.back() << std::endl;
	}
}

int Menu::getSelect(std::string range)
{
	std::cout << "\nВаш выбор: ";
	std::string select;
	int selected = -1;
	while (1)
	{
		getline(std::cin, select);
		int pos = (int)select.find_first_of(range);
		if (pos >= 0)
		{
			selected = select[pos] - '0';
			break;
		}

		std::cout << "Ошибочный выбор. Повторите...\n-->";
	}

	return selected;
}
