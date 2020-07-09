#include <stdio.h>

int collatz(int n, int step_count);

int collatz(int n, int step_count)
	{
	int steps = step_count;
	if (n == 1)
		{
		return steps;
		}
	else if (n % 2 == 0)
		{
		steps += 1;
		return collatz(n/2, steps);
		}
	else if (n % 2 != 0)
		{
		steps += 1;
		return collatz(3*n + 1, steps);
		}
	return steps;
	}

int main(void)
	{
	//int num = getchar();
	//num = num - '0';

	printf("|%3c| |%5s|\n", 'n', "Steps");
	printf("|%3d| |%5d|\n", 1, collatz(1,0));
	printf("|%3d| |%5d|\n", 2, collatz(2,0));
	printf("|%3d| |%5d|\n", 3, collatz(3,0));
	printf("|%3d| |%5d|\n", 4, collatz(4,0));
	printf("|%3d| |%5d|\n", 5, collatz(5,0));
	printf("|%3d| |%5d|\n", 6, collatz(6,0));
	printf("|%3d| |%5d|\n", 7, collatz(7,0));
	}
