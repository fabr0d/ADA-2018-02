#include<iostream>
#include<stdio.h> 
#include<stdbool.h> 
using namespace std;

void printSolution(int **matriz, int fils, int cols){
	for (int i = 0; i < fils; i++){
		for (int j = 0; j < cols; j++)
			printf(" %d ", matriz[i][j]);
		printf("\n");
	}
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(int **matriz, int row, int col, int fils, int cols)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++) {
		if (matriz[row][i]) {
			return false;
		}
	}

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (matriz[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i<fils; i++, j--)
		if (matriz[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int **matriz, int col, int fils, int cols)
{
	/* base case: If all queens are placed
	then return true */
	if (col >= cols)
		return true;
	cout << "columna#: " << col << endl;
	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < fils; i++)
	{
		/* Check if the queen can be placed on
		board[i][col] */
		if (isSafe(matriz, i, col, fils, cols))
		{
			/* Place this queen in board[i][col] */
			matriz[i][col] = 1;

			/* recur to place rest of the queens */
			if (solveNQUtil(matriz, col + 1, fils, cols))
				return true;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			matriz[i][col] = 0; // BACKTRACK 
		}
	}

	/* If the queen cannot be placed in any row in
	this colum col  then return false */
	return false;
}

bool solveNQ(int **matriz, int fils, int cols)
{
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

	printSolution(matriz, fils, cols);
	return true;
}

// driver program to test above function 
int main()
{
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