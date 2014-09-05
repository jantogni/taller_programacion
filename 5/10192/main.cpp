#include <iostream>
#include <string>
#include <algorithm>

const int M = 105;

using namespace std;

int main(){
	string l1, l2;
	int visit[M+5][M+5];

	int n = 0;
	int i, j;

	getline(cin, l1);
	while (cin.good() && (l1[0] != '#')) {
		getline(cin,l2);

        	int s1 = l1.size();
        	int s2 = l2.size();

		l1 = " " + l1;
		l2 = " " + l2;

        	for (i = 0; i <= s1; i++) 
			visit[i][0] = 0;

	        for (i = 0; i <= s2; i++) 
			visit[0][i] = 0;

	        for (i = 1; i <= s1; i++)
        		for (j = 1; j <= s2; j++) {
        			if (l1[i] == l2[j])
					visit[i][j] = visit[i-1][j-1] + 1;
       				else 
					visit[i][j] = max(visit[i-1][j], visit[i][j-1]);
                	}

        cout << "Case #" << ++n << ": you can visit at most " << visit[s1][s2] << " cities." << endl;
	getline(cin,l1);
	}

	return 0;
}
