#include "array_merge.h"
#include <stdlib.h>
#include "../mergesort/mergesort.h"
#include "../mergesort/mergesort.c"

int existsIn(int* arr, int val, int size) {
	int i;
  	for (i=0; i<size; i++) {
    		if(arr[i]==val) {
			return 1;
		}
  	}
  	return 0;
}

int sum(int* arr, int n) {
    	int sum = 0;
    	for (int i = 0; i < n; i++) {
    		sum += arr[i];
    	}
    return sum;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
	int size = sum(sizes, num_arrays);
	int i, j, k;
  	int count;
	int *temp_array, *result;
  	temp_array = (int*) calloc(size,sizeof(int));  
  	for (i=0; i<num_arrays; i++) {
		for(j=0; j<sizes[i]; j++) {
			if(!existsIn(temp_array,values[num_arrays][j],size)) {
				temp_array[count] = values[num_arrays][j];
				count++;
			}
		}
	}

  mergesort(count, temp_array);

  result = (int*) calloc(count+1,sizeof(int)); 
  result[0] = count;

  for(k=0; k<count+1; k++) {
	result[k+1] = temp_array[k];
  }

  free(temp_array);
  return result;
}
