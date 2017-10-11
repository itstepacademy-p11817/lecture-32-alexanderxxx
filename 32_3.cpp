#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>

int** func(int** a, int** b, int** c, int m, int n, int k)
{
	int ii = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			ii = 0;
			while (ii < n)
			{
				c[i][j] = a[i][ii] * b[ii][j];
				ii++;
			}
		}
	}
	return c;
}

void print(int** c, int s, int s1)
{
	for (int i = 0; i < s; i++)
	{
		for (int i2 = 0; i2 < s1; i2++)
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

	int m = 0, n = 0, k = 0;
	std::cout << "m: ";
	std::cin >> m;
	std::cout << "n: ";
	std::cin >> n;
	std::cout << "k: ";
	std::cin >> k;

	int** a = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	int** b = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		b[i] = (int*)malloc(k * sizeof(int));
	}
	int** c = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		c[i] = (int*)malloc(k * sizeof(int));
	}
	for (int i = 0; i < m; i++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			a[i][i2] = rand() % 9 + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int i2 = 0; i2 < k; i2++)
		{
			b[i][i2] = rand() % 9 + 1;
		}
	}



	print(a, m, n);
	print(b, n, k);
	c = func(a, b, c, m, n, k);
	print(c, m, k);
	system("pause");
	return 0;
}