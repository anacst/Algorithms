#include <stdio.h>

int fat(int num) {
	for (int i = 2; i < num; i++)
		if (!(num%i)) return i;
}

int main(void) {
	int num;
	scanf("%d", &num);
	printf("%d", fat(num));
	return 0;
}
