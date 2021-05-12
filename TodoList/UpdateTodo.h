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
	std::string* s;

	std::cout << "Клавиша <Ввод>, чтобы оставить прежнее значение\n";
	std::cout << "Новое наименование " << "(" << todo->GetTodoName() << "): ";
	getline(std::cin, *s);
	if (*s != "\0")
		todo->SetTodoName(*s);

	std::cout << "Новый приоритет: " << "(" << todo->GetTodoPriorityString() << "): ";
	getline(std::cin, *s);
	if (*s != "\0")
		todo->SetTodoPriority(*s);

	std::cout << "Новое описание " << "(" << todo->GetTodoDescription() << "): ";
	getline(std::cin, *s);
	if (*s != "\0")
		todo->SetTodoDescription(*s);
	std::cout << "Новая дата: ";
}