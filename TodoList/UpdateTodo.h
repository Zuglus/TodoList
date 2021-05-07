#pragma once

void UpdateTodo(Todo* arr, int size)
{
	std::cout << "\n> >> Редактирование дела: << <";
	std::cout << "\nID дела, которое редактируем:";
	int* id = new int;
	while (1)
	{
		std::cin >> *id;
		if (*id >= 0 &&
			*id < size)
			break;
		std::cout << "\nОшибочный ID. Повторите...";
	}
	std::cout << "\nВарианты редактирования:";
	std::cout << "\n1 - полностью";
	std::cout << "\n2 - наименование";
	std::cout << "\n3 - приоритет";
	std::cout << "\n4 - описание";
	std::cout << "\n5 - дата";
	int* answer = new int;
	while (1)
	{
		std::cin >> *answer;
		if (*answer > 0 &&
			*answer <= 5)
			break;

		puts("Ошибочный ввод. Повторите...");
	}

	Todo todo = arr[*id];

	switch (*answer)
	{
	case 1:
		std::cout << "Новое наименование: ";
		todo.name = ConsoleEnter(50);
		std::cout << "Новый приоритет: ";
		todo.priority = SetPriority();
		std::cout << "Новое описание: ";
		todo.description = ConsoleEnter(100);
		std::cout << "Новая дата: ";
		SetDate(&todo.date);
		break;
	case 2:
		std::cout << "Новое наименование: ";
		todo.name = ConsoleEnter(50);
		break;
	case 3:
		std::cout << "Новый приоритет: ";
		todo.priority = SetPriority();
		break;
	case 4:
		std::cout << "Новое описание: ";
		todo.description = ConsoleEnter(100);
		break;
	case 5:
		std::cout << "Новая дата: ";
		SetDate(&todo.date);
		break;
	}

	arr[*id] = todo;
}