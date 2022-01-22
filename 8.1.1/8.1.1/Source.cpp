#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


char* ChangeSim(char* dest, const char* cs, char* t, int i)
{
	if (cs[i] != 0)
	{
		if (cs[i] == '+' || cs[i] == '-' || cs[i] == '=')
		{
			strcat(t, "**");
			return ChangeSim(dest, cs, t + 2, i + 1);
		}
		else
		{
			*t++ = cs[i++];
			*t = '\0';
			return ChangeSim(dest, cs, t, i);
		}
	}

	else
	{
		*t++ = cs[i++];
		*t++ = cs[i++];
		*t = '\0';
		return dest;
	}
}

int CountSim(const char* cs, int i)
{
	if (cs[i] != 0)
		if (cs[i] == '+' || cs[i] == '-' || cs[i] == '=')
			return 1 + CountSim(cs, i + 1);
		else
			return CountSim(cs, i + 1);
	else
		return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char cs[101];
	cout << "Ввести: " << endl;
	cin.getline(cs, 100);

	char s[] = "+-=";
	cout << "К-сть: " << CountSim(cs, 0) << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = ChangeSim(dest1, cs, dest1, 0);
	cout << "Вивести: " << dest1 << endl;
	return 0;
}