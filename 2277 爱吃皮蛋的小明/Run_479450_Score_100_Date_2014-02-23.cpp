#include<iostream>
using namespace std;
int n;
long long sum,a[100];
int main()
{
    cin>>n;
    a[1]=1;
    a[2]=2;
    if(n==1) sum=1;
    else if(n==2) sum=2;
    else for(int i=3;i<=n;i++) a[i]=a[i-1]+a[i-2];
    sum=a[n];
    cout<<sum;
    return 0;
}	
