#include <iostream>

std::string ConsoleEnter(int size)
{
	char* enter = new char[size];
	std::cin.getline(enter, size);

	return std::string(enter);
}