#include <stdlib.h>

int findMax(int vet[], int size) {
	int max = vet[0];
	
	for (int i = 1; i < size; i++)
		if (vet[i] > max) 
			max = vet[i];
	
	return max;
}

void countSort(int vet[], int size) {
	int max = findMax(vet, size);
	
	int *output = calloc(max+1, sizeof(int));
	int *count = calloc(max+1, sizeof(int));
	
	for (int i = 0; i < size; i++)
		count[vet[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i-1];

	for (int i = size - 1; i >= 0; i--) 
		output[--count[vet[i]]] = vet[i];

	for (int i = 0; i < size; i++)
		vet[i] = output[i];

	free(output);
	free(count);
}
