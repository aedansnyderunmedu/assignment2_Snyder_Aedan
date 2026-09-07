#include <stdio.h>
#include "statistics.h"
#include "output_array.h"

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

int main()
{
	int rowCount = 6;//fixed table row size for printing
	int n_Max = 500;//VLAs live on the stack; don't want arrays to be too large.
	int n;//array 1 parameter; user input.
	
	printf("Please enter size of table 1:\n");
	if(scanf("%d", &n) != 1 || n > n_Max || n <= 0) //user-defined variable for VLA. Input rejection for characters, negatives, and numbers too great to exist on the stack. 
	{
		outsideError();
		return 1; //rejection/exit
	}
	int table1[n];
		int n1 = n; //saving historical values of n for passing into generic stats function size parameter. 
	fill_Array(table1, n);

	printf("Please enter size of table 2:\n");
	if(scanf("%d", &n) != 1 || n > n_Max || n <= 0)
	{
		outsideError();
		return 1;
	}
	int table2[n];
		int n2 = n;
	fill_Array(table2, n);

	printf("Please enter size of table 3:\n");
	if(scanf("%d", &n) != 1 || n > n_Max || n <= 0)
	{
		outsideError();
		return 1;
	}
	int table3[n];
		int n3 = n;
	fill_Array(table3, n);
	//=====Table 1 Logic=====>
	printf("TABLE 1:\n");
	output_Array(table1, n1, rowCount);
	int max1 = max_Array(table1, n1), min1 = min_Array(table1, n1), abs1 = abs_Array(max1, min1);
	printf("Table 1 metrics:\nSum: %d\nAverage: %lf\nStandard Deviation(sample): %lf\nMax value: %d\nMin value: %d\nTotal range: %d\n", sum_Array(table1, n1), avg_Array(table1, n1), stdev_Array(table1, n1), max1, min1, abs1);
	printf("==============================\n");
	//=====Table 2 Logic=====>
	printf("TABLE 2:\n");
	output_Array(table2, n2, rowCount);
	int max2 = max_Array(table2, n2), min2 = min_Array(table2, n2), abs2 = abs_Array(max2, min2);
	printf("Table 2 metrics:\nSum: %d\nAverage: %lf\nStandard Deviation(sample): %lf\nMax value: %d\nMin value: %d\nTotal range: %d\n", sum_Array(table2, n2), avg_Array(table2, n2), stdev_Array(table2, n2), max2, min2, abs2);
	printf("==============================\n");	
	//=====Table 3 Logic=====>
	printf("TABLE 3:\n");
	output_Array(table3, n3, rowCount);
	int max3 = max_Array(table3, n3), min3 = min_Array(table3, n3), abs3 = abs_Array(max3, min3);
	printf("Table 3 metrics:\nSum: %d\nAverage: %lf\nStandard Deviation(sample): %lf\nMax value: %d\nMin value: %d\nTotal range: %d\n", sum_Array(table3, n3), avg_Array(table3, n3), stdev_Array(table3, n3), max3, min3, abs3);
	printf("==============================\n");
	return 0;
}
