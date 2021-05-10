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

	std::cout << "Клавиша <Ввод>, чтобы оставить прежнее значение\n";
	std::cout << "Новое наименование " << "(" << todo->GetTodoName() << "): ";
	char* tmp = new char[50];
	std::cin.getline(tmp, 50);
	if (tmp[0] != '\0')
		todo->SetTodoName(tmp);
	delete tmp;
	std::cout << "Новый приоритет: " << "(" << todo->GetTodoPriorityString() << "): ";
	std::cin.getline(tmp, 50);
	if (tmp[0] != '\0')
		todo->SetTodoPriority(tmp[0]);
	delete tmp;
	std::cout << "Новое описание " << "(" << todo->GetTodoDescription() << "): ";
	std::cin.getline(tmp, 100);
	if (tmp[0] != '\0')
		todo->SetTodoDescription(tmp);
	std::cout << "Новая дата: ";
}