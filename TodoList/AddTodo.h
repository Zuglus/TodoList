#pragma once

Todo* AddTodo(Todo* oldArr, int *size)
{
	(*size)++;
	Todo* newArr = new Todo[*size];

	for (int i = 0; i < *size - 1; ++i)
		newArr[i] = oldArr[i];
	delete[]oldArr;

	Todo* newTodo = new Todo;
	puts("\n<<< �������� ������ ����: >>>");
	puts("��� ������?");
	getchar();
	gets_s(newTodo->name);

	puts("\n�������� ���������:");
	newTodo->priority = SetPriority();

	puts("\n�������: ");
	getchar();
	gets_s(newTodo->description);

	puts("\n������� ���� � ����� ����������:");
	SetDate(&(newTodo->date));

	newArr[(*size) - 1] = *newTodo;
	delete newTodo;

	return newArr;
}