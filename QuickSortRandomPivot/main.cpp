#include<iostream>
#include<stdlib.h>     /* srand, rand */
#include<time.h>       /* time */
using namespace std;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	cout << " " << endl;
}

int Partition(int a[], int low, int pivot){
	int index, i;
	index = low; // posicion del menor valor
	for (i = low; i < pivot; i++){
		if (a[i] < a[pivot]){
			swap(&a[i], &a[index]);
			index++;
		}
	}
	swap(&a[pivot], &a[index]);
	return index;
}

int RandomPivot(int a[], int low, int high){
	int pvt, n;
	n = rand();
    //random pivote
	pvt = low + n % (high - low + 1);
	//dandole el valor del pivote al ultimo elemto del array
	swap(&a[high], &a[pvt]);
	return Partition(a, low, high);
}

int QuickSort(int a[], int low, int high){
	int pindex;
	if (low < high){
		pindex = RandomPivot(a, low, high);
		QuickSort(a, low, pindex - 1);
		QuickSort(a, pindex + 1, high);
	}
	return 0;
}

int main(){
	int n, i;
	cout << "Numero de elementos del arreglo: ";
	cin >> n;

	int *arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % n + 100;
	}
	print(arr, n);
	QuickSort(arr, 0, n - 1);
	cout << "\nArreglo Ordenado" << endl;
	print(arr, n);
	system("pause");
	return 0;
}