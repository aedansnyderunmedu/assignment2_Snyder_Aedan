#include <stdio.h>
#include <math.h>

int sumFunction (int array[], int size) //computes sum by taking pointer to 1st element of array and size parameter, returns int
{
	int countSum = 0;//local counter variable only
	for (int i = 0; i < size; i++)
	{
		countSum += array[i];
	}
	return countSum;
}
double avgFunction (int array[], int size) //same thing, takes pointer to first element and size parameter and returns average as double
{
	int countSum = 0;
	double avg;
	for (int i = 0; i < size; i++)
	{
		countSum += array[i];
	}
	avg = countSum/(float)size;
	return avg;
}
double sdFunction (int array[], int size) //again returns SD as double and takes pointer to first element of array plus hardcoded size parameter.
{
	double mean = avgFunction(array, size);//function call within function to obtain average
	double squareSum = 0; //final sum of all squared differences; this will be divided by size - 1 for SAMPLE standard deviation. 
	for (int i = 0; i < size; i++)
	{
		double meanDiff = array[i] - mean; //individual difference of index minus mean
		squareSum += meanDiff * meanDiff;//running sum of the squared difference of each operation
	}
	return sqrt(squareSum/(size - 1));//minus 1 for SAMPLE version; population SD would use division by size.
}


int main(void)
{
	int arrayOne[5];//variable declarations and hard-coded/fixed length arrays
	int arrayTwo[6];
	int arrayThree[7];
	int enterNumber;//generic integer to track each user entry
	//ARRAY 1 Fill loop
	printf("Enter 5 integer values for array one:\n");
	for (int i = 0; i < 5; i++)
	{
		if(scanf("%d", &enterNumber) != 1) //super basic input validation/verification
		{
			printf("Erroneous entry; rerun and try again.\n");//generic error message.
			return 1;
		}
		arrayOne[i] = enterNumber;
	}
	//ARRAY 2 Fill loop
	printf("Please enter 6 integer values for array two:\n");
	for (int i = 0; i < 6; i++)
	{
		if(scanf("%d", &enterNumber) != 1)
		{
			printf("Erroneous entry; rerun and try again.\n");
			return 1;
		}
		arrayTwo[i] = enterNumber;
	}
	//ARRAY 3 Fill loop
	printf("Please enter 7 integer values for array three:\n");
	for (int i = 0; i < 7; i++)
	{
		if(scanf("%d", &enterNumber) != 1)
		{
			printf("Erroneous entry; rerun and try again.\n");
			return 1;
		}
		arrayThree[i] = enterNumber;
	}
	
	printf("Array 1 metrics:\nSum: %d\nAvg: %lf\nStandard Deviation: %lf\n", sumFunction(arrayOne, 5), avgFunction(arrayOne, 5), sdFunction(arrayOne, 5));//in-line function calls for each metric instead of new variables for all
	printf("Array 2 metrics:\nSum: %d\nAvg: %lf\nStandard Deviation: %lf\n", sumFunction(arrayTwo, 6), avgFunction(arrayTwo, 6), sdFunction(arrayTwo, 6));
	printf("Array 3 metrics:\nSum: %d\nAvg: %lf\nStanadrd Deviation: %lf\n", sumFunction(arrayThree, 7), avgFunction(arrayThree, 7), sdFunction(arrayThree, 7));

	return 0;

}
