#include "diff.h"
#include "abs_max.h"
#include "abs_min.h"

int diff(int *arr, int count){
	int e_max = abs_max(arr, count);
	int e_min = abs_min(arr, count);
	return e_max-e_min;
}
