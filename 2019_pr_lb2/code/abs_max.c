#include <stdlib.h>
#include "abs_max.h"

int abs_max(int *arr, int count){
	int a_max = abs(arr[0]);
	int elem = arr[0];
	for(int i=0; i<count; i++){
		if(abs(arr[i])>a_max){
			a_max = abs(arr[i]);
			elem = arr[i];
		}
	}
	return elem;
}