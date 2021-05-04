#pragma once

void ShowTodos(Todo* arr, int size)
{
	std::cout << "Список дел:\n";

	if (size)
		for (int i = 0; i < size; ++i)
		{
			ShowTodo(arr[i], i);
		}
	else
		std::cout << "\nДел не запланировано!!!\n";
}