#include <stdio.h>

int main(){
	int xa, xb, xc, ya, yb, yc;
	scanf("%d %d %d\n%d %d %d", &xa, &xb, &xc, &ya, &yb, &yc);
	
	char status = 0;
	if(xa > ya){
		if(xb > yb && xc > yc) status = 1;
		else if(xb > yc && xc > yb) status = 1;
	}
	else if(xa > yb){
		if(xb > yc && xc > ya) status = 1;
		else if(xb > ya && xc > yc) status = 1;
	}
	else if(xa > yc){
		if(xb > yb && xc > ya) status = 1;
		else if(xb > ya && xc > yb) status = 1;
	}
	else if(xa < ya){
		if(xb < yb && xc < yc) status = 1;
		else if(xb < yc && xc < yb) status = 1;
	}
	else if(xa < yb){
		if(xb < yc && xc < ya) status = 1;
		else if(xb < ya && xc < yc) status = 1;
	}
	else if(xa < yc){
		if(xb < yb && xc < ya) status = 1;
		else if(xb < ya && xc < yb) status = 1;
	}
	
	if(status)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
