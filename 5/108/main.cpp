#include<iostream>
#define M 100

using namespace std;

int main(){
	int n;
	cin>>n;

	int i,j;
	int x1, y1, x2, y2;
	int t;

	int table[M+1][M+1];

	for(i=0; i <= n; i++){
		table[0][i]=0;
		table[i][0]=0;
	}

    	for(i=1; i <= n; i++){
		for(j=1;j<=n;j++){
			cin >> t;
			table[i][j] = t+table[i][j-1]+table[i-1][j]-table[i-1][j-1];
        	}
    	}

	int max = table[1][1];

	for(x1=1; x1 <= n; x1++){
		for(y1=1; y1 <= n; y1++){
			for(x2=x1; x2 <= n; x2++){
				for(y2=y1; y2 <= n; y2++){
					t = table[x2][y2]-table[x2][y1-1]-table[x1-1][y2]+table[x1-1][y1-1];
                    			if(t>max) 
						max=t;
				}
			}
		}
	}
	cout << max << endl;
	return 0;
}
