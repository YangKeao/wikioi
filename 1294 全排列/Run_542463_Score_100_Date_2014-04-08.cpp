#include <iostream>
#include <algorithm> 
#include <stdio.h>
using namespace std;
int n;
int a[1000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	a[i-1]=i;
    }
    for(int i=1;i<=n-1;i++) 
    {
        printf("%d ",a[i-1]);
    }
    printf("%d\n",a[n-1]);
    while(next_permutation(a,a+n)){
    	for(int i=1;i<=n-1;i++)
            printf("%d ",a[i-1]);
        printf("%d\n",a[n-1]);
    }
    return 0;
}