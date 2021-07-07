#include <stdio.h>
#include <stdlib.h>
#define N 100

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

int diff(int *arr, int count){
	int e_max = abs_max(arr, count);
	int e_min = abs_min(arr, count);
	return e_max-e_min;
}

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
