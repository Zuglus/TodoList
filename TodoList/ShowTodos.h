#pragma once

void ShowTodos(Todo* arr, int size)
{
	std::cout << "Список дел:\n";

	if (size)
		for (int i = 0; i < size; ++i)
		{
			std::cout << "\nID: " << i << std::endl;
			std::cout << "Наименование: " << arr[i].name << std::endl;
			std::cout << "Приоритет: ";
			GetPriority(arr[i].priority);
			std::cout << "\nПодробности: " << arr[i].description;
			std::cout << "\nСрок исполнения: ";
			GetDate(arr[i].date);
			std::cout << " к ";
			GetTime(arr[i].date);
			std::cout << std::endl;
		}
	else
		std::cout << "\nДел не запланировано!!!\n";
}