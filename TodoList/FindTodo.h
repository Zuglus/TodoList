#pragma once

struct MenuElement
{
	char name[20];
	void (*menuFunc)(Todo* x, int);
};

void ByName(Todo* list, int size)
{
	std::cout << "По какому имени искать?\n";
	std::string toFind = ConsoleEnter(50);

	std::cout << "Ищем...";
	bool isIn = false;
	for (int i = 0; i < size; ++i)
	{
		int finded = list[i].name.find(toFind);
		if (finded >= 0)
		{
			ShowTodo(list[i], i);
			isIn = true;
		}
	}

	if (!isIn)
		std::cout << "\nПо этому имени нет данных\n";
}

void ByPriority(Todo* list, int size)
{
	std::cout << "\nПо какому приоритету ищем? ";
	Priority toFind = SetPriority();

	std::cout << "\nИщем...\n";
	bool isIn = false;
	for (int i = 0; i < size; ++i)
		if (list[i].priority == toFind)
		{
			isIn = true;
			ShowTodo(list[i], i);
		}

	if (!isIn)
		puts("По такому приоритету нет данных");
}

void ByDescription(Todo* list, int size)
{
	std::cout << "Что ищем?";
	std::string toFind = ConsoleEnter(50);

	std::cout << "Ищем...";
	bool isIn = false;
	for (int i = 0; i < size; ++i)
	{
		int finded = list[i].description.find(toFind);
		if (finded >= 0)
		{
			ShowTodo(list[i], i);
			isIn = true;
		}
	}

	if (!isIn)
		std::cout << "\nПо этому описанию нет данных\n";
}

void ByTime(Todo* list, int size)
{

}

void FindTodo(Todo* arr, int size)
{
	const int menuSize = 4;
	MenuElement menu[menuSize] = {
		{" - названию", ByName},
		{" - приоритету", ByPriority},
		{" - описанию", ByDescription},
		{" - времени", ByTime}
	};

	puts(">>> Поиск дел по: <<<");
	for (int i = 0; i < menuSize; ++i)
		std::cout << i + 1 << menu[i].name << std::endl;

	int select;

	while (1)
	{
		std::cin >> select;
		if (select > 0 &&
			select <= 4)
			break;
		puts("Ошибочный выбор. Повторите...");
	}

	menu[select - 1].menuFunc(arr, size);
}