#pragma once

enum Priority
{
	low,
	middle,
	high
};

Priority SetPriority()
{
	puts("1 - ������");
	puts("2 - �������");
	puts("3 - �������");
	int selectedPriority;
	while (true)
	{
		std::cin >> selectedPriority;
		if (selectedPriority > 0 &&
			selectedPriority <= 3)
			break;

		puts("\n��������� �����!!! ���������: ");
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
		std::cout << "������";
		break;
	case middle:
		std::cout << "�������";
		break;
	case high:
		std::cout << "�������";
		break;
	}
}