#include <stdio.h>

int main(){
	float x, y;
	scanf("%f %f", &x, &y);
	
	char status = 0;

	if(x <= 0.0f && y <= 0.0f && x+y >= -2.0)
		status = 1;
	else if(x*x + y*y <= 1.0f)
		status = 1;

	if(status)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
