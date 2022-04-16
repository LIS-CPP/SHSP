#include <stdio.h>

int main(){
    float t;
    scanf("%f", &t);
    float c = 5.0f / 9.0f * (t - 32.0f);
    printf("%.1f\n", c);

    return 0;
}