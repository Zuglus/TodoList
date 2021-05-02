#pragma once

void ShowTodos(Todo* arr, int size)
{
	std::cout << "������ ���:\n";

	if (size)
		for (int i = 0; i < size; ++i)
		{
			std::cout << "\nID: " << i << std::endl;
			std::cout << "������������: " << arr[i].name << std::endl;
			std::cout << "���������: ";
			GetPriority(arr[i].priority);
			std::cout << "\n�����������: " << arr[i].description;
			std::cout << "\n���� ����������: ";
			GetDate(arr[i].date);
			std::cout << " � ";
			GetTime(arr[i].date);
			std::cout << std::endl;
		}
	else
		std::cout << "\n��� �� �������������!!!\n";
}