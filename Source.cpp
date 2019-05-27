#include<iostream>
#include<Windows.h>
using namespace std;

void input_line(char str[], const int n);
int str_len(char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void capitalize(char str[]);
void Shrink(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 20;
	char str[n] = {};
	cout << "Enter string:";
	int counter;
	input_line(str, n);
	cout << str << endl;
	cout << str_len(str) << endl;
	upper_case(str);
	cout << str << endl;
	/*lower_case(str);
	cout << str << endl;*/
	capitalize(str);
	cout << str << endl;
	Shrink(str); cout << str << endl;
}

void input_line(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
int str_len(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void upper_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a'&& str[i] <= 'z' ||
			str[i] >= 'à'&& str[i] <= 'ÿ'
			)
			str[i] -= 32;
	}
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A'&& str[i] <= 'Z' ||
			str[i] >= 'À'&& str[i] <= 'ß'
			)
			str[i] += 32;
	}
}
void capitalize(char str[])
{
	lower_case(str);
	if (str[0] >= 'a'&& str[0] <= 'z' ||
		str[0] >= 'à'&& str[0] <= 'ÿ'
		)str[0] -= 32;
	for (int i = 0; str[i]; i++)
	{
		if (str[i - 1] == ' ' && str[i] >= 'a'&& str[i] <= 'z' ||
			str[i - 1] == ' ' && str[i] >= 'à'&& str[i] <= 'ÿ'
			)str[i] -= 32;
	}
}
void Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i ] == ' ' && str[i+1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
