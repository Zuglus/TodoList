#pragma once

void UpdateTodo(Todo* arr, int size)
{
	puts("\n> >> Редактирование дела: << <");
	puts("ID дела, которое редактируем:");
	int* id = new int;
	while (1)
	{
		std::cin >> *id;
		if (*id >= 0 &&
			*id < size)
			break;
		puts("Ошибочный ID. Повторите...");
	}
	puts("Варианты редактирования:");
	puts("1 - полностью");
	puts("2 - наименование");
	puts("3 - приоритет");
	puts("4 - описание");
	puts("5 - дата");
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
		puts("Новое наименование:");
		getchar();
		gets_s(todo.name);
		puts("Новый приоритет:");
		todo.priority = SetPriority();
		puts("Новое описание:");
		getchar();
		gets_s(todo.description);
		puts("Новая дата:");
		SetDate(&todo.date);
		break;
	case 2:
		puts("Новое наименование:");
		getchar();
		gets_s(todo.name);
		break;
	case 3:
		puts("Новый приоритет:");
		todo.priority = SetPriority();
		break;
	case 4:
		puts("Новое описание:");
		getchar();
		gets_s(todo.description);
		break;
	case 5:
		puts("Новая дата:");
		SetDate(&todo.date);
		break;
	}

	arr[*id] = todo;
}