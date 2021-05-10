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
	char* tempS = new char[50];
	std::cin.ignore();
	std::cin.getline(tempS, 50);
	if (tempS[0] != '\0')
		newTodo->SetTodoName(tempS);

	std::cout << "Выберите приоритет:\n";
	std::cout << "1. низкий\n";
	std::cout << "2. средний\n";
	std::cout << "3. высокий\n";
	std::cin.getline(tempS, 50);
	if (tempS[0] != '\0')
		newTodo->SetTodoPriority(tempS[0]);

	std::cout << "Добавьте подробности: ";
	std::cin.ignore();
	std::cin.getline(tempS, 100);
	if (tempS[0] != '\0')
		newTodo->SetTodoDescription(tempS);
	delete[]tempS;

	std::cout << "Введите дату и время исполнения:";
	while (1)
	{
		char tmp[100];
		int tmpInt;
		tm* newDate = new tm;
		*newDate = *newTodo->GetTodoLocalDate();

		std::cout << "\nДата (" << newDate->tm_mday << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 31)
				newDate->tm_mday = tmpInt;
		}

		std::cout << "Месяц (" << newDate->tm_mon + 1 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 12)
				newDate->tm_mon = tmpInt - 1;
		}

		std::cout << "Год (" << newDate->tm_year + 1900 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			IsNumber(tmp))
		{
			newDate->tm_year = atoi(tmp);
		}

		std::cout << "Часы (" << newDate->tm_hour << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 23)
				newDate->tm_hour = tmpInt;
		}

		std::cout << "Минуты (" << newDate->tm_min << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt < 60)
				newDate->tm_min = tmpInt;
		}

		newDate->tm_sec = 0;

		if (newTodo->SetTodoDate(newDate))
			break;
		std::cout << "Ошибочная дата. Повторите...";
	}

	newArr[(*size) - 1] = *newTodo;
	delete newTodo;

	return newArr;
}