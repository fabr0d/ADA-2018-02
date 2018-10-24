#include<iostream>
#include<stdio.h> 
using namespace std;

//Funcion para saber si se salio del tablero
bool VerificarPaso(int x, int y, int **sol, int fils, int cols){
	return (x >= 0 && x < fils && y >= 0 && y < cols && sol[x][y] == -1);
}

void printMatriz(int **sol, int fils, int cols){
	for (int x = 0; x < fils; x++)
	{
		for (int y = 0; y < cols; y++)
			printf(" %2d ", sol[x][y]);
		printf("\n");
	}
}

bool backtracking(int x, int y, int pasoi, int **sol, int xMovimientos[8], int yMovimientos[8], int fils, int cols){
	int k, next_x, next_y;
	if (pasoi == fils * cols) {
		return true;
	}
	//cout << "pos inicial: " << x << " " << y << endl;
	//prueba todos los movimientos posibles del caballo a su alrededor
	for (k = 0; k < 8; k++){
		next_x = x + xMovimientos[k];
		next_y = y + yMovimientos[k];
		if (VerificarPaso(next_x, next_y, sol, fils, cols)){
			//cout << "nueva pos valida: " << next_x << " " << next_y << endl;
			sol[next_x][next_y] = pasoi;
			if (backtracking(next_x, next_y, pasoi + 1, sol, xMovimientos, yMovimientos, fils, cols) == true) {
				return true;
			}
			else {
				sol[next_x][next_y] = -1;// backtracking 
				//cout << "retrosede" << endl;
			}
		}
	}
	return false;
}

bool RecorridoCaballo(int x1,int y1,int **sol,int fils,int cols){

	//LLena la matriz con -1 para indicar que ninguna a sido recorrida
	for (int x = 0; x < fils; x++) {
		for (int y = 0; y < cols; y++) {
			sol[x][y] = -1;
		}
	}
	//posibles movimientos del punto inicial (x+?)(y+?)
	int xMovimientos[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int yMovimientos[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	//Posicion inicial marcada como el 1er movimiento
	sol[x1][y1] = 0;

	if (backtracking(x1, y1, 1, sol, xMovimientos, yMovimientos, fils, cols) == false){
		printf("Solution no existe");
		return false;
	}
	else {
		printMatriz(sol, fils, cols);
	}
	return true;
}

int main()
{
	int fils, cols;
	cout << "Dimensiones de la matriz: " << endl;
	cout << "fils: ";
	cin >> fils;
	cout << "cols: ";
	cin >> cols;

	int x1, y1;
	cout << "Ingrese la posicion del caballo: " << endl;
	cout << "x: ";
	cin >> x1;
	cout << "y: ";
	cin >> y1;

	int** matriz = new int*[fils];
	for (int i = 0; i < fils; ++i) {
		matriz[i] = new int[cols];
	}

	RecorridoCaballo(x1,y1,matriz,fils,cols);
	system("pause");
	return 0;
}