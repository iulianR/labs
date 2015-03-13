// void insertion_sort

int * copy_array (int *a, int n) {
	int *copy = new int[n];
	for (int i = 0; i < n; i++) {
		copy[i] = a[i];
	}

	return copy;
}

void display_array (int *v, int n) {
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
}

int main ()
{
	int *v = new int[10] {5, 4, 3, 7, 2, 9, 8, 1, 3, 6};
	int n = 10;

	cout << "Array:" << endl;
	display_array (v, n);

	cout << "Insertion_sort:" << endl;
	// insertion_sort (v, n);
	delete[] v;
	return 0;
}