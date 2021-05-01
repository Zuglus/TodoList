#pragma once

enum Priority
{
	low,
	middle,
	high
};

struct Data
{
	int day;
	int month;
	int year;
	int hour;
	int minuts;
};

struct Todo
{
	char name[50];
	Priority priority;
	char description[100];
	Data data;
};