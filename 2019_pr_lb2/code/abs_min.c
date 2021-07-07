#include <stdlib.h>
#include "abs_min.h"

int abs_min(int *arr, int count){
	int a_min = abs(arr[0]);
	int elem = arr[0];
	for(int i=0; i<count; i++){
		if(abs(arr[i])<a_min){
			a_min = abs(arr[i]);
			elem = arr[i];
		}
	}
	return elem;
}