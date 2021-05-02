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
	puts("1 - ������");
	puts("2 - �������");
	puts("3 - �������");
	int selectedPriority;
	while (1)
	{
		cin >> selectedPriority;
		if (selectedPriority > 0 &&
			selectedPriority <= 3)
			break;

		puts("\n��������� �����!!! ���������: ");
	}

	switch (selectedPriority)
	{
	case 1:
		newTodo->priority = low;
		break;
	case 2:
		newTodo->priority = middle;
		break;
	case 3:
		newTodo->priority = high;
		break;
	}

	puts("\n�������: ");
	getchar();
	gets_s(newTodo->description);

	puts("\n������� ���� � ����� ����������:");
	puts("���� (DD): ");
	cin >> newTodo->data.day;
	puts("����� (MM): ");
	cin >> newTodo->data.month;
	puts("��� (YYYY): ");
	cin >> newTodo->data.year;
	puts("��� (HH): ");
	cin >> newTodo->data.hour;
	puts("������ (MM): ");
	cin >> newTodo->data.minuts;

	newArr[(*size) - 1] = *newTodo;

	return newArr;
}