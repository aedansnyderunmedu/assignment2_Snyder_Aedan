#include <stdio.h>
#include "output_array.h"

void output_Array(const int *array, int n, int rowCount)
{
	for(int i = 0; i < n; i++)
	{
		printf("[%2d ]", array[i]);//looks a little better than lone numbers
		if((i + 1)%rowCount == 0)//index lags behind 1; when desired entries per row reached, print a newline
			printf("\n");
	}
	printf("\n");//for partial rows
}
