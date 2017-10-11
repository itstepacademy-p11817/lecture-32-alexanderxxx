#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>

int** func(int** a, int** b, int** c, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int i2 = 0; i2 < s; i2++)
		{
			c[i][i2] = a[i][i2] + b[i][i2];
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
	int** b = (int**)malloc(s * sizeof(int*));
	for (int i = 0; i < s; i++)
	{
		b[i] = (int*)malloc(s * sizeof(int));
	}
	int** c = (int**)malloc(s * sizeof(int*));
	for (int i = 0; i < s; i++)
	{
		c[i] = (int*)malloc(s * sizeof(int));
	}
	for (int i = 0; i < s; i++)
	{
		for (int i2 = 0; i2 < s; i2++)
		{
			a[i][i2] = rand() % 9 + 1;
			b[i][i2] = rand() % 9 + 1;
		}

	}
	print(a, s);
	print(b, s);
	c = func(a, b, c, s);
	print(c, s);
	system("pause");
	return 0;
}