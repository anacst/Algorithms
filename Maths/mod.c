#include <stdio.h>
#define uint unsigned int

uint mod(uint a, uint e, uint d) {
	return (a%d)*e;
}

int main(void) {

	uint a, e, d;

	printf("Digite a: "); scanf("%d", &a);
	printf("Digite e: "); scanf("%d", &e);
	printf("Digite d: "); scanf("%d", &d);

	printf("O resultado é %d\n", mod(a, e, d));

	return 0;
}
