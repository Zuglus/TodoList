#pragma once

Todo* AddTodo(Todo* oldArr, int *size)
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
	puts("1 - низкий");
	puts("2 - средний");
	puts("3 - высокий");
	int selectedPriority;
	while (1)
	{
		cin >> selectedPriority;
		if (selectedPriority > 0 &&
			selectedPriority <= 3)
			break;

		puts("\nОшибочный выбор!!! Повторите: ");
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

	puts("\nОпишите: ");
	getchar();
	gets_s(newTodo->description);

	puts("\nВведите дату и время исполнения:");
	puts("День (DD): ");
	cin >> newTodo->data.day;
	puts("Месяц (MM): ");
	cin >> newTodo->data.month;
	puts("Год (YYYY): ");
	cin >> newTodo->data.year;
	puts("Час (HH): ");
	cin >> newTodo->data.hour;
	puts("Минуты (MM): ");
	cin >> newTodo->data.minuts;

	newArr[(*size) - 1] = *newTodo;

	return newArr;
}