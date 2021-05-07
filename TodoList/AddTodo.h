#pragma once

Todo* AddTodo(Todo* oldArr, int* size)
{
	(*size)++;
	Todo* newArr = new Todo[*size];

	for (int i = 0; i < *size - 1; ++i)
		newArr[i] = oldArr[i];
	delete[]oldArr;

	Todo* newTodo = new Todo;
	std::cout << "\n<<< Создание нового дела: >>>\n";

	std::cout << "\nЧто нужно сделать: ";
	getchar();
	newTodo->name = ConsoleEnter(50);

	std::cout << "\nВыберите приоритет:\n";
	newTodo->priority = SetPriority();

	std::cout << "\nДобавьте подробности: ";
	getchar();
	newTodo->description = ConsoleEnter(100);

	std::cout << "\nВведите дату и время исполнения:";
	SetDate(&(newTodo->date));

	newArr[(*size) - 1] = *newTodo;
	delete newTodo;

	return newArr;
}