#pragma once

void UpdateTodo(Todo* arr, int size)
{
	puts("\n> >> �������������� ����: << <");
	puts("ID ����, ������� �����������:");
	int* id = new int;
	while (1)
	{
		std::cin >> *id;
		if (*id >= 0 &&
			*id < size)
			break;
		puts("��������� ID. ���������...");
	}
	puts("�������� ��������������:");
	puts("1 - ���������");
	puts("2 - ������������");
	puts("3 - ���������");
	puts("4 - ��������");
	puts("5 - ����");
	int* answer = new int;
	while (1)
	{
		std::cin >> *answer;
		if (*answer > 0 &&
			*answer <= 5)
			break;

		puts("��������� ����. ���������...");
	}

	Todo todo = arr[*id];

	switch (*answer)
	{
	case 1:
		puts("����� ������������:");
		getchar();
		gets_s(todo.name);
		puts("����� ���������:");
		todo.priority = SetPriority();
		puts("����� ��������:");
		getchar();
		gets_s(todo.description);
		puts("����� ����:");
		SetDate(&todo.date);
		break;
	case 2:
		puts("����� ������������:");
		getchar();
		gets_s(todo.name);
		break;
	case 3:
		puts("����� ���������:");
		todo.priority = SetPriority();
		break;
	case 4:
		puts("����� ��������:");
		getchar();
		gets_s(todo.description);
		break;
	case 5:
		puts("����� ����:");
		SetDate(&todo.date);
		break;
	}

	arr[*id] = todo;
}