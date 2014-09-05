#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int isPalindrome(string str){
	unsigned int i;
	unsigned int l = str.size();
	for(i=0; i<l; i++)
		if(str[i] != str[l-i-1])
			return 0;
	return 1;
}

int isMirrored(string str){
	string mstr = str;

	unsigned int i;
	unsigned int l = str.size();
	
	for(i=0; i<l; i++){
		switch(mstr[i]){
			case 'E':
				mstr[i]='3';
				break;
			case '3':
				mstr[i]='E';
				break;
			case 'J':
				mstr[i]='L';
				break;
			case 'L':
				mstr[i]='J';
				break;
			case 'S':
				mstr[i]='2';
				break;
			case '2':
				mstr[i]='S';
				break;
			case 'Z':
				mstr[i]='5';
				break;
			case '5':
				mstr[i]='Z';
				break;
			case 'A':
			case 'H':
			case 'I':
			case 'M':
			case 'T':
			case 'U':
			case 'V':
			case 'X':
			case 'O':
			case 'Y':
			case '1':
			case '8':
			case 'W':
				continue;
				break;
			default:return 0;
		}
	}
	for(i=0; i<l; i++)
		if(str[i] != mstr[l-i-1])
			return 0;
	return 1;
}

int main(int argc, char* argv[]){
	int palindrome, mirrored;
	
	string str;
        getline(cin,str);

	while(cin.good()){
		palindrome = isPalindrome(str);
		mirrored = isMirrored(str);

		if(palindrome){
			if(mirrored)
				cout << str << " -- is a mirrored palindrome." << endl << endl;
			else
				cout << str << " -- is a regular palindrome." << endl << endl;
		}
		else{
			if(mirrored)
				cout << str << " -- is a mirrored string." << endl << endl;
			else 
				cout << str << " -- is not a palindrome." << endl << endl;
		}
		getline(cin,str);
	}
return 0;
}
