#include "array_merge.h"
#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

int existsIn(int *arr, int val, int size)
{
  int i = 0;
  for (i = 0; i < size; i++)
  {
    if (arr[i] == val)
    {
      return 1;
    }
  }

  return 0;
}

int sum(int *arr, int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];
  }

  return sum;
}

int* array_merge(int num_arrays, int *sizes, int **values)
{
  int size = sum(sizes, num_arrays);
  int i = 0, j = 0, k = 0, count = 0;
  int *temp_array, *result;
  
  // Set the temporary array size to the sum of all the arrays sizes (for the worst case of all values being unique)
  temp_array = (int*) calloc(size, sizeof(int));

  // Loop through all of the arrays using the inputted values,
  // checking if it's already in our temp array before adding and counting our unique values
  for (i = 0; i < num_arrays; i++)
  {
    for (j = 0; j < sizes[i]; j++)
    {
      if (existsIn(temp_array, values[i][j], count) == 0)
      {
        temp_array[count] = values[i][j];
        count++;
      }
    }
  }
  
  // Sort our populated temp array using our counter as the bound for the range
  mergesort(count, temp_array);

  // Allocate our result with our counter as the size, plus 1 for the size at the beginning0
  result = (int*) calloc(count + 1, sizeof(int));
  result[0] = count;

  // Copy over the values to our result
  for (k = 1; k < count + 1; k++)
  {
    result[k] = temp_array[k-1];
  }

  // Clean our temporary array
  free(temp_array);
  return result;
}
