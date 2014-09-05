#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <map>

using namespace std;

int main ()
{
	int testCase;
	cin >> testCase;
	
	while ( testCase-- ) {
		int input;
		vector <int> v;
		map <vector <int>, int> pressCnt;
		map <vector <int>, bool> visited;
		queue <vector <int> > q;
		
		for ( int i = 0; i < 4; i++ ) {
			cin >> input;
			v.push_back (input);
		}
		
		pressCnt [v] = 0;
		q.push (v);
		
		vector <int> dest;
		
		for ( int i = 0; i < 4; i++ ) {
			cin >> input;
			dest.push_back (input);
		}
		
		int n;
		cin >> n;
		
		for ( int i = 0; i < n; i++ ) {
			v.clear ();
			for ( int j = 0; j < 4; j++ ) {
				cin >>input;
				v.push_back (input);
			}
			visited [v] = true;
		}
		
		bool resultFound = false;
		
		while ( !q.empty () ) {
			v.clear ();
			v = q.front ();
			q.pop ();
			
			if ( visited [v] == true )
				continue;
			
			visited [v] = true;
			
			if ( v == dest ){
				resultFound = true;
				break;
			}
			
			vector <int> child = v;
			
			for ( int i = 0; i < 4; i++ ) {
				child [i] += 1;
				child [i] %= 10;
				q.push (child);
				pressCnt [child] = pressCnt [v] + 1;
				child = v;
			}
			
			for ( int i = 0; i < 4; i++ ){
				child [i] -= 1;

				if ( child [i] == -1 ) 
					child [i] = 9;
				if ( visited [child] == false ) 
					q.push (child);

				pressCnt [child] = pressCnt [v] + 1;
				child = v;
			}
		}
		
		if ( resultFound ) 
			cout << pressCnt [dest] << endl;
		else 
			cout << "-1" << endl;
	}

	return 0;
}
