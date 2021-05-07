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
	tm* tmpDate = new tm;
	localtime_s(tmpDate, &now);

	while (1)
	{
		char tmp[100];
		int tmpInt;

		std::cout << "\nДата (" << tmpDate->tm_mday << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 31)
				tmpDate->tm_mday = tmpInt;
		}

		std::cout << "Месяц (" << tmpDate->tm_mon + 1 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 12)
				tmpDate->tm_mon = tmpInt - 1;
		}

		std::cout << "Год (" << tmpDate->tm_year + 1900 << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			IsNumber(tmp))
		{
				tmpDate->tm_year = atoi(tmp);
		}

		std::cout << "Часы (" << tmpDate->tm_hour << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt <= 23)
				tmpDate->tm_hour = tmpInt;
		}

		std::cout << "Минуты (" << tmpDate->tm_min << "): ";
		std::cin.getline(tmp, 100);
		if (tmp[0] != '\0' &&
			strlen(tmp) < 3 &&
			IsNumber(tmp))
		{
			tmpInt = atoi(tmp);
			if (tmpInt > 0 &&
				tmpInt < 60)
				tmpDate->tm_min = tmpInt;
		}

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