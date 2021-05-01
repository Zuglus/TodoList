#pragma once

Todo* AddTodo(Todo* oldArr, int *size)
{
	(*size)++;
	Todo* newArr = new Todo[*size];

	for (int i = 0; i < *size - 1; ++i)
		newArr[i] = oldArr[i];
	delete[]oldArr;

	Todo* newTodo = new Todo;
	puts("<<< Создание нового дела: >>>");
	puts("Введите название: ");
	getchar();
	cin.getline(newTodo->name, 50);
	puts(newTodo->name);

	return newArr;
}