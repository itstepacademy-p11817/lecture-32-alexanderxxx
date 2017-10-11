#include <iostream>
#include <cstdlib>
#include <utility>
#include <time.h>
#include <string.h>
#include <stdio.h>

int** func(int** m1, int s)
{

	char n;
	int count = 0;

	while (true)
	{
		for (int i = 0; i < s; i++)
		{
			for (int i2 = 0; i2 < s; i2++)
			{
				std::cout << m1[i][i2] << " ";
				if (i2 == s - 1)
				{
					std::cout << '\n';
				}
			}
		}
		std::cout << '\n';

		std::cout << "Направление(u/d/l/r): ";
		std::cin >> n;
		std::cout << "Количество сдвигов: ";
		std::cin >> count;
		system("cls");
		if (n == 'u')
		{
			while (count > 0)
			{
				for (int i = 0; i < s; i++)
				{
					for (int i2 = 0; i2 < s; i2++)
					{
						if (i == s - 1)
						{
							break;
						}
						std::swap(m1[i][i2], m1[i + 1][i2]);
					}
				}
				count--;
			}
		}

		if (n == 'd')
		{
			while (count > 0)
			{
				for (int i = s - 1; i > 0; i--)
				{
					for (int i2 = s - 1; i2 >= 0; i2--)
					{
						std::swap(m1[i][i2], m1[i - 1][i2]);
						if (i == 0)
						{
							break;
						}
					}
				}
				count--;
			}

		}



		if (n == 'l')
		{
			while (count > 0)
			{
				for (int i = 0; i < s; i++)
				{
					for (int i2 = 0; i2 < s; i2++)
					{
						if (i2 == s - 1)
						{
							break;
						}
						std::swap(m1[i][i2], m1[i][i2 + 1]);
					}
				}
				count--;
			}
		}



		if (n == 'r')
		{
			while (count > 0)
			{
				for (int i = s - 1; i >= 0; i--)
				{
					for (int i2 = s - 1; i2 >= 0; i2--)
					{
						if (i2 == 0)
						{
							break;
						}
						std::swap(m1[i][i2], m1[i][i2 - 1]);

					}
				}
				count--;
			}

		}


	}
}



int main()
{
	setlocale(0, "");

	int s = 0;
	std::cout << "size: ";
	std::cin >> s;
	system("cls");

	int** a = (int**)malloc(s * sizeof(int*));
	for (int i = 0; i < s; i++)
	{
		a[i] = (int*)malloc(s * sizeof(int));
	}


	for (int i = 0; i < s; i++)
	{
		for (int i2 = 0; i2 < s; i2++)
		{
			a[i][i2] = rand() % 9 + 1;
		}

	}

	func(a, s);
	system("pause");
	return 0;
}