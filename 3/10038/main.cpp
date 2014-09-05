#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
	int n;
	int i;
	int d;
	int count;
	while (cin >> n){
		vector<int> diff(static_cast<vector<int>::size_type>(n-1), 0);
		vector<int> values(static_cast<vector<int>::size_type>(n), 0);
		count = 0;

		for (i = 0; i < n; i++)
			cin >> values[i];

		for (i = 0; i < n-1; i++){
			d = abs(values[i] - values[i+1]);
			if(d && d < n) 
				diff[d-1] = 1;
		}

		for (i = 0; i < n-1; i++) {
			if(diff[i] == 1)
				count++;
		}

		if(n == count+1)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	return 0;
}
