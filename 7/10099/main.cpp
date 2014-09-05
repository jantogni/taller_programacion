#include <iostream>
#include <math.h>

#define NMAX 101

using namespace std;

typedef struct {
    unsigned long weight[NMAX+1][NMAX+1];
    int numV;
} aMatrix;

int max( int a, int b){
	if( a > b) return a;
	return  b;
}

int min( int a, int b){
	if( a > b) return b;
	return a;
}

int init_aMatrix(aMatrix *g) {
    int i,j;
    g->numV = 0;
    for (i=1; i<=NMAX; i++) {
            for (j=1; j<=NMAX; j++) {
                g->weight[i][j] = 0;
            }
    }
    return 0;
}

int read_aMatrix(aMatrix *g, int numV, int nedges) {
    int x,y;
    unsigned long w;
    init_aMatrix(g);
        
    g->numV = numV;

    for (int i=0; i<nedges; i++) {
        cin >> x >> y >> w; 
            w--;
            g->weight[x][y] = w;
            g->weight[y][x] = w;
    }                  
    return 0;
}

void maximin(aMatrix *g) {
    int i,j;
    int k;
    for (k=1; k<=g->numV; k++) {
        for (i=1; i<=g->numV; i++) {
            for (j=1; j<=g->numV; j++) {
                g->weight[i][j] = max(g->weight[i][j], min(g->weight[i][k], g->weight[k][j]));
            }
        }
    }
}

int main() {
	int scenC, numC, numR;
	int from, to, numT;
	aMatrix graph;
	    
	scenC = 0;    
	cin >> numC >> numR;
	
	while ((numC != 0) || (numR != 0)) {
		scenC++;
		
		read_aMatrix(&graph, numC, numR);
		cin >> from >> to >> numT;
		maximin(&graph);
		
		cout << "Scenario #" << scenC << endl;
		cout << "Minimum Number of Trips = " << ceil((double)numT / graph.weight[from][to]) << endl << endl;  
		cin >> numC >> numR;
	}
	return 0;    
}
