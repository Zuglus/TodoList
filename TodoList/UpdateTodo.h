#pragma once

void UpdateTodo(Todo* arr, int size)
{
	std::cout << "\n> >> Редактирование дела: << <";
	std::cout << "\nID дела, которое редактируем: ";
	int id;
	while (1)
	{
		std::cin >> id;
		if (id >= 0 &&
			id < size)
			break;
		std::cout << "\nОшибочный ID. Повторите...\n";
	}

	Todo* todo = &arr[id];
	std::string* tmp = new std::string;

	std::cout << "Клавиша <Ввод>, чтобы оставить прежнее значение\n";
	std::cout << "Новое наименование " << "(" << todo->name << "): ";
	*tmp = ConsoleEnter(50);
	if (tmp[0] != "\0")
		todo->name = *tmp;
	std::cout << "Новый приоритет: ";
	todo->priority = SetPriority();
	std::cout << "Новое описание " << "(" << todo->description << "): ";
	*tmp = ConsoleEnter(100);
	if (tmp[0] != "\0")
		todo->description = *tmp;
	std::cout << "Новая дата: ";
}