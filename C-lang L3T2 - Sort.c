#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const unsigned int Arr_Size = 256;

void printArray(int* arr, unsigned int size){
	for(unsigned int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
}

/*
void bubbleSortArray(int* arr, unsigned int size){
	int tmp;
	for(unsigned int i = 0; i < size; ++i)
		for(unsigned int j = 1; j < size - i; ++j)
			if(arr[j-1] > arr[j]){
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
}
*/

void quickSortArray(int* arr, unsigned int size){
	void swap(int* x, int* y){
		int tmp;
		tmp = *x;
		*x  = *y;
		*y  = tmp;
	}
	void quicksort(int* arr, unsigned int begin, unsigned int end){
		int basemark  = end - 1;
		int leftmark  = begin;
		int rightmark = basemark - 1;
		int state     = 1;
		
		if(leftmark >= basemark) return;
		
		while(1){
			if(state){
				if(leftmark == basemark)
					break;
				else if(arr[leftmark] >= arr[basemark])
					state = 0;
				else
					++leftmark;
			} else {
				if(rightmark == leftmark)
					break;
				else if(arr[rightmark] < arr[basemark]){
					state = 1;
					swap(&arr[rightmark], &arr[leftmark]);
				}
				else
					--rightmark;
			}
		}
		swap(&arr[leftmark], &arr[basemark]);
		quicksort(arr, begin, leftmark);
		quicksort(arr, leftmark+1, end);
	}
	quicksort(arr, 0, size);
}

int main(){
	int arr[Arr_Size];
	unsigned int it;
	srand(time(NULL));
	
	for(unsigned int i = 0; i < Arr_Size; ++i)
		arr[i] = rand() & 0xff;
	
	printArray(arr, Arr_Size);
	printf("\n\n");
	// bubbleSortArray(arr, Arr_Size);
	quickSortArray(arr, Arr_Size);
	printArray(arr, Arr_Size);
	printf("\n");
	
	return 0;
}
