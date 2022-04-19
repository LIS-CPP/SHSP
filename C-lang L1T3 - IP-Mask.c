#include <stdio.h>

int main(){
	int ip1, ip2, ip3, ip4, m1, m2, m3, m4;
	scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4);
	scanf("%d.%d.%d.%d", &m1, &m2, &m3, &m4);

	printf("%d.%d.%d.%d\n", ip1&m1,ip2&m2,ip3&m3,ip4&m4);

	return 0;
}