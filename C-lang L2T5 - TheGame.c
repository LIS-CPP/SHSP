// Стратегия для быстрого достижения результата: "Двоичный поиск"
#include <stdio.h>
#include <time.h>

int main(){
	const char* less = "less";
	const char* bigger = "bigger";
	int randomNum = time(NULL) % 100 + 1;
	int number = 0;
	const char* msg = NULL;
	
	printf("%s", "Guess the number from 1 to 100: ");

	do {
		scanf("%d", &number);
		
		if(number > randomNum)
			msg = less;
		else if(number < randomNum)
			msg = bigger;
		else{
			printf("%s", "Congratulations! You win!\n");
			break;
		}
		printf("The number is %s than that!\nTry again: ", msg);
	}
	while(1);
	
	return 0;
}
