#include<iostream>
#include<stdio.h> 
#include<stdbool.h> 
using namespace std;

void printMatriz(int **matriz, int fils, int cols){
	for (int i = 0; i < fils; i++){
		for (int j = 0; j < cols; j++)
			printf(" %d ", matriz[i][j]);
		printf("\n");
	}
	cout << " " << endl;
}

bool validarPosicion(int **matriz, int row, int col, int fils, int cols){
	int i, j;
	//verifica si hay reinas al lado izquierdo 
	for (i = 0; i < col; i++) {
		if (matriz[row][i]) {
			return false;
		}
	}
	//verifica si hay reinas en la diagolan superior
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (matriz[i][j]) {
			return false;
		}
	}
	//verifica si hay reinas en la diagonal inferior
	for (i = row, j = col; j >= 0 && i < fils; i++, j--) {
		if (matriz[i][j]) {
			return false;
		}
	}
	return true;
}

bool solveNQUtil(int **matriz, int col, int fils, int cols){
	//si todas las reinas han sido colocadas - Condicion de parada
	if (col >= cols) {
		return true;
	}
	//busca colocar la reina columna por columna
	for (int i = 0; i < fils; i++){
		//mira si puede poner la reina en la posicion matriz[i][col]
		if (validarPosicion(matriz, i, col, fils, cols)){
			//pone la reina
			matriz[i][col] = 1;
			printMatriz(matriz, fils, cols);
			//pasa a la siguiente columna
			if (solveNQUtil(matriz, col + 1, fils, cols)) { 
				return true;
			}
			//si la reina colocada no da la solucion entonces la borra
			matriz[i][col] = 0; // backtrack 
			printMatriz(matriz, fils, cols);
		}
	}

	/* If the queen cannot be placed in any row in
	this colum col  then return false */
	return false;
}

bool solveNQ(int **matriz, int fils, int cols){
	//llenar la matriz con 0 para dejarla lista
	for (int x = 0; x < fils; x++) {
		for (int y = 0; y < cols; y++) {
			matriz[x][y] = 0;
		}
	}
	if (solveNQUtil(matriz, 0, fils, cols) == false){
		cout << "no hay solucion: " << endl;
		return false;
	}
	printMatriz(matriz, fils, cols);
	return true;
}

int main(){
	int fils, cols;
	cout << "Dimensiones de la matriz: " << endl;
	cout << "fils: ";
	cin >> fils;
	cout << "cols: ";
	cin >> cols;

	/*int queens;
	cout << "numero de reinas: " << endl;
	cin >> queens;*/

	int** matriz = new int*[fils];
	for (int i = 0; i < fils; ++i) {
		matriz[i] = new int[cols];
	}

	solveNQ(matriz, fils, cols);

	system("pause");
	return 0;
}