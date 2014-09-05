#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;

int main(int argc, char* argv[]){
	char keyboard[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	unsigned int i, j, flag;

	string str;
        getline(cin,str);
	
	while(cin.good()){
		unsigned int l = str.size();
		for(i=0; i<l; i++){
			flag = 0;
			for(j=0; j<47; j++){
				if(str[i] == keyboard[j]){
					flag = 1;
					printf("%c",keyboard[j-1]);
					break;
				}
			}
			if (flag == 0)
				printf("%c",str[i]);
		}
		printf("\n");
		getline(cin,str);
	}
return 0;
}
