#pragma once

using namespace std;

Todo* DelTodo(Todo* oldArr, int* size)
{
	(*size)--;
	Todo* newArr = new Todo[*size];

	puts("> >> �������� ������ �� ��� << <");
	cout << "������� ID: ";
	int id;
	while (1)
	{
		cin >> id;
		if (id >= 0 &&
			id <= *size)
			break;
		puts("��������� ����. ���������...");
	}

	if (*size > 0)
		for (int i = 0; i < *size; ++i)
		{
			if (i < id)
				newArr[i] = oldArr[i];
			else
				newArr[i] = oldArr[i + 1];
		}

	cout << "\n���� � ID: " << id << " �������.\n";

	return newArr;
}