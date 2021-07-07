#include <stdio.h>
#define N 100
#include "abs_max.h"
#include "abs_min.h"
#include "diff.h"
#include "sum.h"


int main(){
	int arr[N];
	int count = 0;
	int option;
	char c;

	scanf("%d", &option);
	for(int i=0; i<N; i++){
		scanf("%d%c", &arr[i], &c);
		count++;
		if(c=='\n'){
			break;
		}
	}

	switch (option){
		case 0:
			printf("%d\n", abs_max(arr, count));
		break;

		case 1:
			printf("%d\n", abs_min(arr, count));
		break;

		case 2:
			printf("%d\n", diff(arr, count));
		break;

		case 3:
			printf("%d\n", sum(arr, count));
		break;

		default:
			printf("Данные некорректны\n");
	}
	
	
return 0;
}