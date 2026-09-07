#include <stdlib.h> //needed for abs function
#include <math.h> //needed for sqrt
#include "statistics.h" //quotes to specify THIS directory. stats.h is my custom header, not included in the main c toolchain. 

double stdev_Array(const int *array, int n) //old functions just ported over from assignment 1. same logic. 
{
	double mean = avg_Array(array, n);
	double squareSum = 0;
	for(int i = 0; i < n; i++)
	{
		double meanDiff = array[i] - mean;
		squareSum += meanDiff * meanDiff;
	}
	return sqrt(squareSum/(n - 1));
}

double avg_Array(const int *array, int n)
{
	int countSum = 0;
	double avg;
	for(int i = 0; i < n; i++)
		countSum += array[i];
	avg = countSum/(double)n;
	return avg;
}

int sum_Array(const int *array, int n)
{
	int countSum = 0;
	for(int i = 0; i < n; i++)
		countSum += array[i];
	return countSum;
}

int max_Array(const int *array, int n)
{
	int max = array[0];//first element for init comparison
	for(int i = 0; i < n; i++)
	{
		if(max <= array[i])
			max = array[i];
	}
	return max;
}

int min_Array(const int *array, int n)
{
	int min = array[0];//as above
	for(int i = 0; i < n; i++)
	{
		if(min >= array[i])
			min = array[i];
	}
	return min;
}

int abs_Array(int max, int min)
{
	int diff = (max - min);
	diff = abs(diff);
	return diff;
}

