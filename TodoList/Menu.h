#pragma once

class Menu
{
public:
	Menu();
	void show(bool);
	int getSelect(bool);
private:
	int menuLength;
	std::string* menuList;
};
