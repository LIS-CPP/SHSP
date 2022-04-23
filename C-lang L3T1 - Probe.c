#include <stdio.h>

const unsigned int arr_size = 4;

int main(){
	int arr[arr_size];
	unsigned int it;
	
	it = 0;
	while(it < arr_size)
		scanf("%d", &arr[it++]);
	
	it = arr_size;
	while(it != 0)
		printf("%d ", arr[--it]);
	
	return 0;
}
