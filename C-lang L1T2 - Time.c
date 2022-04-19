#include <stdio.h>

int main(){
	int sec = 0;
	scanf("%d", &sec);
	int min = sec/60;
	printf("%02d:%02d:%02d\n", min/60%60, min%60, sec%60);

	return 0;
}