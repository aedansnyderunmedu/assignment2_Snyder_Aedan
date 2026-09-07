#include <math.h>
#include "statistics.h" //quotes to specify THIS directory. stats.h is my custom header, not included in the main c toolchain. 

double stdev_Array(*array, n)
{
	double mean = avg_Array(array, n);
	double squareSum = 0;
	for(int i = 0; i < n; i++)
	{
		double meanDiff = array[i] - mean;
		squareSum += meanDiff * meanDiff;
	}
	return sqrt(squareSum/(size - 1));
}

double avg_Array(*array, n)
{
	int countSum = 0;
	double avg;
	for(int i = 0; i < n; i++)
	{
		countSum += array[i];
	}
	avg = countSum/(double)size;
	return avg;
}

int sum_Array(*array, n)
{
	int countSum = 0;
	for(int i = 0; i < n; i++)
	{
		countSum += array[i];
	}
	return countSum;
}


