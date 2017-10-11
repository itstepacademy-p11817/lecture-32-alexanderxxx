#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>

int** func(int** a, int* s)
{
	int m = 0;
	for (int i = 0; i < *s; i++)
	{
		for (int i2 = 0; i2 < *s; i2++)
		{
			if (a[i][i2] == 0)
			{
				a[i] = NULL;
				m++;
				break;
			}
		}
	}
	(*s) -= m;
	int** c = (int**)malloc((*s) * sizeof(int*));


	for (int i = 0; i < *s; i++)
	{
		if (a[i] != NULL)
		{
			c[i] = a[i];
		}
	}
	return c;
}

void print(int** c, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int i2 = 0; i2 < s; i2++)
		{
			std::cout << c[i][i2] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}


int main()
{
	setlocale(0, "");

	int s = 0;
	std::cout << "size: ";
	std::cin >> s;

	int** a = (int**)malloc(s * sizeof(int*));
	for (int i = 0; i < s; i++)
	{
		a[i] = (int*)malloc(s * sizeof(int));
	}


	for (int i = 0; i < s; i++)
	{
		for (int i2 = 0; i2 < s; i2++)
		{
			a[i][i2] = rand() % 18 - 9;
		}

	}
	print(a, s);
	int** c = func(a, &s);
	print(c, s);
	system("pause");
	return 0;
}