#pragma once

Todo* DelTodo(Todo* oldArr, int* size)
{
	(*size)--;
	Todo* newArr = new Todo[*size];

	puts("> >> �������� ������ �� ��� << <");
	std::cout << "������� ID: ";
	int id;
	while (1)
	{
		std::cin >> id;
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

	std::cout << "\n���� � ID: " << id << " �������.\n";

	return newArr;
}