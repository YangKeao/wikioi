#include <iostream>
#include <cstdio>
using namespace std;
int n;
int s[12],t;
int main(){
	scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&t);
        s[t]++;
    }
    for(int i=1;i<=10;i++){
    	for(int j=1;j<=s[i];j++)
            printf("%d\n",i);
    }
    return 0;
}