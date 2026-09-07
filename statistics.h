#ifndef STATISTICS_H //if undefined
#define STATISTICS_H //define. INCLUDE guards to prevent using my stats.h more than once

double avg_Array(const int *array, int n); //All basic prototypes. same implementation as before in assignment 1. 
double stdev_Array(const int *array, int n); //Const for never changing array values during computation
int sum_Array(const int *array, int n); //
int max_Array(const int *array, int n); //
int min_Array(const int *array, int n); //
int abs_Array(int max, int min);

#endif //close header
