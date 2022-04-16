#include <stdio.h>

int main(){
	static int n = 0;
  char ch;
  scanf("%c", &ch);
  if(ch != '\n' && ch != '\0'){
		++n;
    main();
    printf("%c", ch);
  }
	if(n--==0) printf('\n');
 
  return 0;
}
