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
	std::string* tempS = new std::string(ConsoleEnter(50));
	if (tempS[0] != "\0")
		newTodo->name = *tempS;
	delete tempS;

	std::cout << "\nВыберите приоритет:\n";
	tempS = new std::string(ConsoleEnter(50));
	if (tempS[0] != "\0")
		newTodo->priority = SetPriority();
	delete tempS;

	std::cout << "\nДобавьте подробности: ";
	tempS = new std::string(ConsoleEnter(100));
	if (tempS[0] != "\0")
		newTodo->description = *tempS;
	delete tempS;

	std::cout << "\nВведите дату и время исполнения:";
	while (1)
	{
		char tmp[100];
		int tmpInt;

		std::cout << "\nДата (" << newTodo->date.tm_mday << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 31)
				newTodo->date.tm_mday = tmpInt;
		}

		std::cout << "Месяц (" << newTodo->date.tm_mon + 1 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 12)
				newTodo->date.tm_mon = tmpInt - 1;
		}

		std::cout << "Год (" << newTodo->date.tm_year + 1900 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			IsNumber(tmp))
		{
			newTodo->date.tm_year = atoi(tmp);
		}

		std::cout << "Часы (" << newTodo->date.tm_hour << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 23)
				newTodo->date.tm_hour = tmpInt;
		}

		std::cout << "Минуты (" << newTodo->date.tm_min << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt < 60)
				newTodo->date.tm_min = tmpInt;
		}

		newTodo->date.tm_sec = 0;


		time_t inSeconds = mktime(&(*newTodo).date);
		if (inSeconds > time(NULL))
			break;
		std::cout << "Ошибочная дата. Повторите...";
	}

	newArr[(*size) - 1] = *newTodo;
	delete newTodo;

	return newArr;
}