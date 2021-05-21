#pragma once

class Input
{
public:
	std::string get(std::string);
	int get(int);
	int get(int, int, int);
private:
	std::string userInput;
	int getSelect(std::string);
	bool isNumber(std::string);
};

