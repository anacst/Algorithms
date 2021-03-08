#include <stdlib.h>
#include <math.h>

int findMax(int vet[], int size) {
	int max = vet[0];
	
	for (int i = 1; i < size; i++)
		if (vet[i] > max) 
			max = vet[i];
	
	return max;
}

void countSort(int vet[], int size, int exp) {
	
	int *aux = calloc(size, sizeof(int));

	for (int i = 0; i < size; i++)
		aux[i] = (vet[i]/(int)pow(10, exp))%10;

	int max = findMax(aux, size);
	
	int *output = calloc(max+1, sizeof(int));
	int *count = calloc(max+1, sizeof(int));

	for (int i = 0; i < size; i++)
		count[aux[i]]++;

	for (int i = 1; i <= max; i++)
		count[i] += count[i-1];

	for (int i = size - 1; i >= 0; i--) 
		output[--count[aux[i]]] = vet[i];

	for (int i = 0; i < size; i++)
		vet[i] = output[i];

	free(aux);
	free(output);
	free(count);
}


int getMax(int vet[], int size) {
	int *tmp = malloc(size*sizeof(int));
	int max_count = 0;
	
	for (int i = 0; i < size; i++)
		tmp[i] = vet[i];

	for (int i = 0; i < size; i++) {
		int count = 0;
		while (tmp[i] > 0 && ++count)
			tmp[i] /= 10;
		if (count > max_count) max_count = count;
	}

	free(tmp);
	return max_count;
}

void radixSort(int vet[], int size) {
	int qnt_max_digit = getMax(vet, size);

	for (int exp = 0; exp < qnt_max_digit; exp++)
		countSort(vet, size, exp);
}
