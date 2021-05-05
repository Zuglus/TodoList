#pragma once

enum Priority
{
	low,
	middle,
	high
};

Priority SetPriority()
{
	puts("1 - низкий");
	puts("2 - средний");
	puts("3 - высокий");
	int selectedPriority;
	while (true)
	{
		std::cin >> selectedPriority;
		if (selectedPriority > 0 &&
			selectedPriority <= 3)
			break;

		puts("\nОшибочный выбор!!! Повторите: ");
	}

	switch (selectedPriority)
	{
	case 1:
		return low;
	case 2:
		return middle;
	case 3:
		return high;
	}
}

void GetPriority(Priority priority)
{
	switch (priority)
	{
	case low:
		std::cout << "низкий";
		break;
	case middle:
		std::cout << "средний";
		break;
	case high:
		std::cout << "высокий";
		break;
	}
}