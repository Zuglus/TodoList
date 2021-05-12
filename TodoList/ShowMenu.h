#pragma once

int ShowMenu(const char* names[], const int size, int todoSize)
{
	system("cls");
	std::cout << "\nМеню:\n";
	if (todoSize)
		for (int i = 0; i < size; ++i)
			std::cout << i + 1 << names[i] << std::endl;
	else
	{
		std::cout << 1 << names[0] << std::endl;
		std::cout << 2 << names[size - 1] << std::endl;
	}

	int selected;
	while (1)
	{
		std::cout << "\nВыберите пункт меню:\n--> ";
		std::cin >> selected;
		if (todoSize &&
			selected - 1 >= 0 &&
			selected <= size)
			break;
		if (selected == 1 ||
			selected == 2)
		{
			if (selected == 2)
				selected = size;
			break;
		}

		std::cout << "Ошибочный выбор!\n";
	}

	return selected;
}