#include <iostream>
#include <stdlib.h>

int bubble(int array[], int size){
	int i, j;
	int flip, aux;

	flip = 0;

	for (i = 0; i < size; i++){
		for (j = 0; j < size - 1; j++){
			if (array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
				flip++;
			}
		}
	}
	return flip;
}

using namespace std;

int main(){
	int *p;
	int n, i, flip;
	flip = 0;

	while (cin >> n){
		p = (int*) malloc ( n*sizeof(int));
		for (i = 0; i < n; i++){
			cin >> p[i];
		}

		flip = bubble(p, n);

		cout << "Minimum exchange operations : " << flip << endl;
	}
	free(p);
	return 0;
}
