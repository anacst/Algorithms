void insertionSort (int vet[], int size) {
	for (int i = 1; i < size; i++) {
		int x = vet[i];
		int j = i - 1;
		while (j >= 0 && vet[i] > vet[j]) {
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = x;
	}
}
