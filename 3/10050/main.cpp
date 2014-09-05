#include <iostream>
#include <vector>
 
#define NDAYS 3650
 
using namespace std;

int main () {
	vector<int> st(NDAYS+1);	
	int nCases;
	int nDays;
	int nParties;
	int Hartal;
	int nDaysLosts;
        int i,j,k;

        cin >> nCases;
        
        for (i=0; i<nCases; i++) {
                cin >> nDays;
                cin >> nParties;              
                nDaysLosts = 0;

		for (j=0; j<=nDays; j++) {
                        st[j] = 0;
                } 

                for (j=0; j<nParties; j++) {
                        cin >> Hartal;
                        for ( k=1; k*Hartal-1 <= nDays; k++) {
                                st[k*Hartal-1] = 1;
                        }
                }
                
                for (j=0; j<nDays; j++) {
                        if ((j%7 != 5) && (j%7 != 6) && (st[j] == 1)) {
                                nDaysLosts++;
                        }
                }
                cout << nDaysLosts << endl;
        }
	return 0; 
}

