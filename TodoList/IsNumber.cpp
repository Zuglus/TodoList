#include <string>

bool IsNumber(char* elem)
{
	char numbers[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

	bool isNumber = false;
	for (int i = 0; i < strlen(elem); ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (elem[i] == numbers[j])
				isNumber = true;
		}
		if (!isNumber)
			return false;
		isNumber = false;
	}
	return true;
}