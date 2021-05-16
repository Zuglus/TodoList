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
	std::string* s = new std::string;

	std::cout << "Клавиша <Ввод>, чтобы оставить прежнее значение\n";
	std::cout << "Новое наименование " << "(" << todo->name() << "): ";
	getline(std::cin, *s);
	if (*s != "\0")
		todo->name(*s);

	std::cout << "Новый приоритет: " << "(" << todo->priorityString() << "): ";
	getline(std::cin, *s);
	if (*s != "\0")
		todo->priority(*s);

	std::cout << "Новое описание " << "(" << todo->description() << "): ";
	getline(std::cin, *s);
	if (*s != "\0")
		todo->description(*s);
	std::cout << "Новая дата: ";
}