#include <stdio.h>

void insertion_sort (int* vet, int size) {
	for (int i = 1; i < size; i++) {
		int x = vet[i];
		int j = i - 1;
		while (j >= 0 && x < vet[j]) {
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = x;
	}
}

void shell_sort (int* v, int size, int* intervals, int numin) {

	int i, j, h = intervals[0];
	int aux[size];

	for (i = 0; i < h; i++) {
		for (j = 0; (j*h)+i < size; j++) 
			aux[j] = v[(j*h)+i];
		insertion_sort(aux, j);
		for (j = 0; (j*h)+i < size; j++)
			v[(j*h)+i] = aux[j];		
	}
	
	if(numin == 1) return;
	shell_sort(v, size, intervals+1, numin-1);
}

int main(void) {
	int vet[8] = {25, 57, 48, 37, 12, 92, 86, 33};
	int h[3] = {5, 3, 1};
	
	shell_sort(vet, 8, h, 3);

	for (int i=0; i<8; i++) 
		printf("%d ", vet[i]);
	
	return 0;
}
