#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 500005

using namespace std;

unsigned long long w;
int num[M],snum[M];

void Merge(int first,int mid,int last){
	int i=first;
	int h=first;
	int j=mid+1;
	int k;

	while( (h<=mid) && (j<=last) ){
		if(num[h]<=num[j]){
			snum[i++]=num[h++];
			w+=i-h;
		}
		else{
		    snum[i++]=num[j++];
		}
	}
	if( h>mid )
    		for(k=j;k<=last;k++)
        		snum[i++]=num[k];
	else
    		for(k=h;k<=mid;k++)
        		snum[i++]=num[k],w+=i-k-1;

	for(k=first;k<=last;k++)
    		num[k]=snum[k];
}

void MergeSort(int first,int last){
	if(first<last){
		int mid=(first+last)/2;
		MergeSort(first,mid);
		MergeSort(mid+1,last);
		Merge(first,mid,last);
	}
}

int main(){
    int n,i;

    while( (cin >> n) && n){
        for(i=0;i<n;i++)
            scanf("%d",&num[i]);
        w=0;
        MergeSort(0,n-1);

	cout << w << endl;
    }

    return 0;
}
