#pragma once

Todo* AddTodo(Todo* oldArr, int *size)
{
	setlocale(LC_ALL, "Ru");
	(*size)++;
	Todo* newArr = new Todo[*size];

	for (int i = 0; i < *size - 1; ++i)
		newArr[i] = oldArr[i];
	delete[]oldArr;

	Todo* newTodo = new Todo;
	puts("<<< Создание нового дела: >>>");
	puts("Введите название: ");
	char s[80];
	gets_s(s);
	puts(s);

	return newArr;
}