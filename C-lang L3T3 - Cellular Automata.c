#include <stdio.h>
#include <time.h>
#include <unistd.h>

const int Array_Size = 75;
const char Rules[35] = { 
	 30, 110,  45,  60,  62,
	 72,  73,  74,  75,  82,
	 86,  88,  89,  90,  94,
	101, 102, 104, 105, 106,
	108, 109, 118, 120, 126,
	134, 138, 144, 146, 148,
	150, 166, 180, 182, 210
	};

void swapPtr(char** x, char** y){
	char* tmp = *x;
	*x = *y;
	*y = tmp;
}

char getBitByRule(char rule, char* arr, char index){
	return 0b1 & rule >> (arr[index-1]<<2 | arr[index]<<1 | arr[index+1]);
}

void printArray(char* arr, int size){
	for(int i = 0; i < size; ++i)
			printf("%c", arr[i] ? '#' : ' ');
}

int main(){
	char A[Array_Size + 2];
	char B[Array_Size + 2];
	char *a, *b;
	
	for(int k = 0; ; ++k){
		if(k >= sizeof(Rules)) k = 0;
		a = A;
		b = B;
		
		for(int i = 0; i < Array_Size + 2; ++i) a[i] = b[i] = 0;
		++a; ++b;
		a[Array_Size/2 + 1] = 1;
		
		printArray(a, Array_Size);
		printf("\n");
		
		for(int i = 0; i < Array_Size/2; ++i){
			for(int j = 0; j < Array_Size; ++j)
				b[j] = getBitByRule(Rules[k], a, j);
			
			printArray(b, Array_Size);
			printf("\n");
			swapPtr(&a, &b);
			usleep(10 * 1000);
		}
		usleep(400 * 1000);
	}
	
	return 0;
}

























