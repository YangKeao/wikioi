#include<iostream>
using namespace std;
int main()
{
    int n,i;
    long long a[91];    
    cin>>n;
    a[0]=0;
    a[1]=2;
    a[2]=4;
    for(i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
    cout<<a[n];
    return 0;
}