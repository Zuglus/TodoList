// Input.cpp

#include <iostream>
#include <string>
#include "Input.h"
#include "Todo.h"

int Input::getSelect(std::string range)
{
	std::cout << "\nВаш выбор: ";
	std::string select;
	int selected = -1;
	while (1)
	{
		getline(std::cin, select);
		if (select.empty()) return -1;
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

std::string Input::get(std::string elem)
{
	getline(std::cin, userInput);

	return userInput.empty() ?
		elem :
		userInput;
}

int Input::get(int elem)
{
	const char* priorityList[3]{
		"низкий",
		"средний",
		"высокий" };
	int pos{ 0 };

	for (const char* i : priorityList)
		std::cout << ++pos << ". " << i << std::endl;

	int select = getSelect("123");

	return select < 0 ? elem : select - 1;
}

bool Input::isNumber(std::string elem)
{
	int pos = (int)elem.find_first_not_of("1234567890");
	return pos < 0 ? true : false;
}

int Input::get(int num, int min, int max)
{
	getline(std::cin, userInput);
	if (userInput.empty())
		return num;
	if (isNumber(userInput))
	{
		int tmp = std::atoi(userInput.c_str());
		if (tmp >= min && tmp < max)
			num = tmp;
	}
	return num;
}