#include <stdio.h>

int main(){
	float x;
	scanf("%f", &x);
	if(x >= 2.0f || x <= -2.0f)
		x = 0;
	else if(x > 1.0f)
		x = 2.0f - x;
	else if(x < -1.0f)
		x = -2.0f - x;
	printf("%.1f\n", x);
	
	return 0;
}
