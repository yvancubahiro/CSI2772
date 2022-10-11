/*MonFichier3.cpp : Ex3 Devoir2 CSI2772A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	int ** triangle = new int *[n];
	

	if(n>=1){
		*triangle = new int[1];
		triangle [0][0] = 1;
	}

	if(n>=2){
		*(triangle+1) = new int[2];
		triangle[1][0] = 1;
		triangle[1][1] = 1;
	}
	
	if(n>=3){

		for(int i = 2; i<n; i++){

			*(triangle+i) = new int[i+1];
			//initialize first value
			triangle[i][0] = 1;
			//initialize last value
			triangle[i][i] = 1;

			//calculate middle pascal values
			for(int j = 1; j<i ; j++){
				triangle [i][j] = triangle[i-1][j]+triangle[i-1][j-1];
			}
		}

	}

	return triangle;

}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}