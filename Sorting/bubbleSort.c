int* bubble_sort (int* vet, int size) {
	for (int i = size-1; i >= 1; i--) 
		for (int j = 0; j < i; i++) 
			if (vet[j] > vet[j+1]) {
				int aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}

	return vet;
}
