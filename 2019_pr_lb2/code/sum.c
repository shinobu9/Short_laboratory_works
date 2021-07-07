#include "sum.h"
#include "abs_max.h"

int sum(int *arr, int count){
	int e_max = abs_max(arr, count);
	int answer = 0;
	for(int i=0;i<count;i++){
		if((arr[i]==e_max)||(e_max==0)){
			answer += arr[i];
			e_max = 0;
		}
	}
	return answer;
}