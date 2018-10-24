#include<stdio.h> 
#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void print(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	cout << " " << endl;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high]; 
	int i = (low - 1);  // Posicion del menor elemento
	for (int j = low; j <= high - 1; j++){
		// si el elemento actual es menos o igual al pivote
		if (arr[j] <= pivot){
			i++;    // incrementa en uno la posicion del menor elemento 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high){
	if (low < high){
		//division del arreglo
		int pi = partition(arr, low, high);
		//division de los 2 lados recursivamente 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main(){
	cout << "ingrese el numero de elementos: ";
	int tam;
	cin >> tam;
	int *arr = new int[tam];
	//int eval[7] = { 5,3,7,6,2,1,4 };
	srand(time(NULL));
	for (int i = 0; i < tam; i++) {
		*(arr + i) = rand() % tam+100;
		//*(arr + i) = eval[i];
	}
	print(arr, tam);
	quickSort(arr, 0, tam - 1);
	print(arr, tam);
	delete[] arr;
	system("pause");
	return 0;
}