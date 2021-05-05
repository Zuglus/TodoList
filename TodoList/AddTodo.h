#pragma once

Todo* AddTodo(Todo* oldArr, int* size)
{
	(*size)++;
	Todo* newArr = new Todo[*size];

	for (int i = 0; i < *size - 1; ++i)
		newArr[i] = oldArr[i];
	delete[]oldArr;

	Todo* newTodo = new Todo;
	puts("\n<<< Создание нового дела: >>>");
	puts("Как назовём?");
	getchar();
	gets_s(newTodo->name);

	puts("\nВыберите приоритет:");
	newTodo->priority = SetPriority();

	puts("\nОпишите: ");
	getchar();
	gets_s(newTodo->description);

	puts("\nВведите дату и время исполнения:");
	SetDate(&(newTodo->date));

	newArr[(*size) - 1] = *newTodo;
	delete newTodo;

	return newArr;
}