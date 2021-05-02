#pragma once

enum Month
{
	january = 1,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december
};

struct Date
{
	int day;
	Month month;
	int year;
	int hour;
	int minuts;
};

void SetDate(Date* date)
{
	std::cout << "���� (1):";
	int* tmpDay = new int(1);
	while (1)
	{
		std::cin >> *tmpDay;
		if (*tmpDay > 0 &&
			*tmpDay <= 31)
			break;
		puts("��������� ����. ���������...");
	}
	date->day = *tmpDay;
	delete tmpDay;

	puts("����� (���):");
	puts("1 - ������");
	puts("2 - �������");
	puts("3 - ����");
	puts("4 - ������");
	puts("5 - ���");
	puts("6 - ����");
	puts("7 - ����");
	puts("8 - ������");
	puts("9 - ��������");
	puts("10 - �������");
	puts("11 - ������");
	puts("12 - �������");
	std::cout << "--> ";
	int* tmpMonth = new int(5);
	while (1)
	{
		std::cin >> *tmpMonth;
		if (*tmpMonth > 0 &&
			*tmpMonth <= 12)
			break;
		puts("��������� ����. ���������...");
	}
	switch (*tmpMonth)
	{
	case 1:
		date->month = january;
		break;
	case 2:
		date->month = february;
		break;
	case 3:
		date->month = march;
		break;
	case 4:
		date->month = april;
		break;
	case 5:
		date->month = may;
		break;
	case 6:
		date->month = june;
		break;
	case 7:
		date->month = july;
		break;
	case 8:
		date->month = august;
		break;
	case 9:
		date->month = september;
		break;
	case 10:
		date->month = october;
		break;
	case 11:
		date->month = november;
		break;
	case 12:
		date->month = december;
		break;
	}
	delete tmpMonth;

	std::cout << "��� (2021): ";
	int* tmpYear = new int(2021);
	while (1)
	{
		std::cin >> *tmpYear;
		if (*tmpYear >= 2021)
			break;
		puts("�������� ���. ���������...");
	}
	date->year = *tmpYear;
	delete tmpYear;

	std::cout << "��� (12): ";
	int* tmpHour = new int(12);
	while (1)
	{
		std::cin >> *tmpHour;
		if (*tmpHour >= 0 &&
			*tmpHour < 24)
			break;
		puts("����� ��� �� 0 �� 23...");
	}
	date->hour = *tmpHour;
	delete tmpHour;

	std::cout << "������ (0): ";
	int* tmpMinuts = new int(0);
	while (1)
	{
		std::cin >> *tmpMinuts;
		if (*tmpMinuts >= 0 &&
			*tmpMinuts < 60)
			break;
		puts("������� ������ �� 0 �� 59...");
	}
	date->minuts = *tmpMinuts;
	delete tmpMinuts;
}

void GetDate(Date date)
{
	date.day / 10 ? std::cout << date.day : std::cout << '0' << date.day;
	std::cout << '.';
	date.month / 10 ? std::cout << date.month : std::cout << '0' << date.month;
	std::cout << '.';
	std::cout << date.year;
}

void GetTime(Date date)
{
	date.hour / 10 ? std::cout << date.hour : std::cout << '0' << date.hour;
	std::cout << ':';
	date.minuts / 10 ? std::cout << date.minuts : std::cout << '0' << date.minuts;
}