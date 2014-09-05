#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(){
	unsigned int numWords = 0, i = 0;

	string str;
	getline(cin,str);

	unsigned int l = str.size();

	while(cin.good()){	
		i = 0;	
		numWords = 0;
		while(i < l){
			if(isalpha(str[i])){
				numWords++;
				while( (i < l) && isalpha(str[i]) ) 
					i++;
			}
			else {
				i++;
			}
		}
		cout<<numWords<<endl;
		getline(cin,str);
		l = str.size();
	}
return 0;
}
