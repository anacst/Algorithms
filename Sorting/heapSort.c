#include <stdio.h>

void swap(int* a, int*b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void heapify(int vet[], int i, int size) {
	int max = i;
	int l = (2*i)+1;
	int r = (2*i)+2;
	
	if (l < size && vet[l] > vet[i])
		max = l;
	if (r < size && vet[r] > vet[i])
		max = r;

	if (max != i) {
		swap(&vet[max], &vet[i]);
		heapify(vet, max, size);
	}
}

void heapSort(int vet[], int size) {
	
	for (int i = (size/2)+1; i >= 0; i--)
		heapify(vet, i, size);

	for (int i = size-1; i >= 0; i--) {
		swap(&vet[0], &vet[i]);
		heapify(vet, 0, i);
	}
}

int main(void) {
	int v[5] = {44, 55, 12, 42, 94};
	heapSort(v, 5);

	for (int i = 0; i < 5; i++)
		printf("%d ", v[i]);
	
	return 0;
}
