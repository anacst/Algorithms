#include <stdio.h>

int indexMin(int vet[], int size) {
	int min = vet[0];
	int idMin = 0;
	for (int i = 1; i < size; i++)
		if (vet[i] < min) idMin = i;
	return idMin;
}

void swap(int* a, int* b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

void selectionSort(int vet[], int size) {
	for (int i = 0; i < size; i++) {
		int min = indexMin(vet+i, size-i) + i;
		swap(&vet[i], &vet[min]);	
	}	
}
