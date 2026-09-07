#include <stdio.h>

int main()
{
	void insideError(void)
	{
		printf("Invalid entry; use integers only for this step.\n");//error printer for repetitive errors
	}

	void outsideError(void)
	{
		printf("Invalid entry; choose a positive integer <= 500 for this step.\n");
	}
	
	int fill_Array(int *array, int n) //array fill function, takes n for size/loop and returns success or fail code
	{
		printf("Please enter values for specified table:\n");
		for(int i = 0; i < n; i++)
		{
			if(scanf("%d", &array[i]) != 1)
			{
				insideError();
				return 1;
			}
		}
		return 0;
	}
	
	int n_Max = 500;
	int n;//array 1 parameter; user input.
	
	printf("Please enter size of table 1:\n");
	if(scanf("%d", &n) != 1 || n > n_Max || n <= 0) //user-defined variable for VLA. Input rejection for characters, negatives, and numbers too great to exist on the stack. 
	{
		outsideError();
		return 1; //rejection/exit
	}
	int table1[n];
	fill_Array(table1, n);

	printf("Please enter size of table 2:\n");
	if(scanf("%d", &n) != 1 || n > n_Max || n <= 0)
	{
		outsideError();
		return 1;
	}
	int table2[n];
	fill_Array(table2, n);

	printf("Please enter size of table 3:\n");
	if(scanf("%d", &n) != 1 || n > n_Max || n <= 0)
	{
		outsideError();
		return 1;
	}
	int table3[n];
	fill_Array(table3, n);

	return 0;
}
