#pragma once

struct MenuElement
{
	char name[20];
	void (*menuFunc)(Todo* x, int);
};

bool IsElemIn(char* toFind, char* src, bool isIn)
{
	for (int i = 0; i < strlen(src); ++i)
	{
		if (src[i] == toFind[0])
		{
			bool exact = true;
			for (int j = 0; j < strlen(toFind); ++j)
				if (src[i + j] != toFind[j])
				{
					exact = false;
					break;
				}
			if (!exact)
				break;
			isIn = true;
			return true;
		}
	}
	return false;
}

void ByName(Todo* list, int size)
{
	puts("�� ������ ����� ������?");
	char name[50];
	getchar();
	gets_s(name);

	puts("����...");
	bool isIn = false;
	for (int i = 0; i < size; ++i)
	{
		if (IsElemIn(name, list[i].name, isIn))
			ShowTodo(list[i], i);
	}

	if (!isIn)
		puts("�� ����� ����� ��� ������");
}

void ByPriority(Todo* list, int size)
{
	puts("�� ������ ���������� ����?");
	Priority toFind = SetPriority();

	puts("����...");
	bool isIn = false;
	for (int i = 0; i < size; ++i)
		if (list[i].priority == toFind)
		{
			isIn = true;
			ShowTodo(list[i], i);
		}

	if (!isIn)
		puts("�� ������ ���������� ��� ������");
}

void ByDescription(Todo* list, int size)
{
	puts("��� ����?");
	char toFind[100];
	getchar();
	gets_s(toFind);

	puts("����...");
	bool isIn = false;
	for (int i = 0; i < size; ++i)
	{
		if (IsElemIn(toFind, list[i].description, isIn))
			ShowTodo(list[i], i);
	}

	if (!isIn)
		puts("� ����� ��������� ��� ������");
}

void ByTime(Todo* list, int size)
{

}

void FindTodo(Todo* arr, int size)
{
	const int menuSize = 4;
	MenuElement menu[menuSize] = {
		{" - ��������", ByName},
		{" - ����������", ByPriority},
		{" - ��������", ByDescription},
		{" - �������", ByTime}
	};

	puts(">>> ����� ��� ��: <<<");
	for (int i = 0; i < menuSize; ++i)
		std::cout << i + 1 << menu[i].name << std::endl;

	int select;

	while (1)
	{
		std::cin >> select;
		if (select > 0 &&
			select <= 4)
			break;
		puts("��������� �����. ���������...");
	}

	menu[select - 1].menuFunc(arr, size);
}