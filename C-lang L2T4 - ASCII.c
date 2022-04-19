#include <stdio.h>

int main(){
	char ch = '!';
	do { printf("%d | %c\n", ch, ch); }
	while(ch++ < '~');
	
	return 0;
}
