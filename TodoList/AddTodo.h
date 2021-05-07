#pragma once

Todo* AddTodo(Todo* oldArr, int* size)
{
	(*size)++;
	Todo* newArr = new Todo[*size];

	for (int i = 0; i < *size - 1; ++i)
		newArr[i] = oldArr[i];
	delete[]oldArr;

	Todo* newTodo = new Todo;
	std::cout << "\n<<< Создание новой задачи: >>>\n";

	std::cout << "\nЧто нужно сделать?: ";
	newTodo->name = ConsoleEnter(50);

	std::cout << "\nВыберите приоритет:\n";
	newTodo->priority = SetPriority();

	std::cout << "\nДобавьте подробности: ";
	newTodo->description = ConsoleEnter(100);

	std::cout << "\nВведите дату и время исполнения:";
	time_t now = time(NULL);
	tm* tmpDate = localtime(&now);
	
	while (1)
	{
		int tmp;
		std::cout << "Дата: ";
		std::cin >> tmp;
		tmpDate->tm_mday = tmp;
		std::cout << "Месяц: ";
		std::cin >> tmp;
		tmpDate->tm_mon = tmp - 1;
		std::cout << "Год: ";
		std::cin >> tmp;
		tmpDate->tm_year = tmp - 1900;
		std::cout << "Часы: ";
		std::cin >> tmp;
		tmpDate->tm_hour = tmp;
		std::cout << "Минуты: ";
		std::cin >> tmp;
		tmpDate->tm_min = tmp;
		tmpDate->tm_sec = 0;

		time_t inSeconds = mktime(tmpDate);
		if (inSeconds > time(NULL))
			break;
		std::cout << "Ошибочная дата. Повторите...";
	}

	newTodo->date = *tmpDate;
	newArr[(*size) - 1] = *newTodo;
	delete newTodo;

	return newArr;
}