#include<iostream>
long long n,m,k,x,tmp,ans;
using namespace std;
long long pow(int k,int d)
{
     if(d==1) return k%n;
     long long t;
     t=pow(k,d/2);
     if (d%2==0) return (t%n)*(t%n);
     if (d%2!=0) return (t%n)*(t%n)*(k%n);
}
int main()
{
    cin>>n>>m>>k>>x;
    ans=(pow(10,k)*m+x)%n;
    cout<<ans;
    return 0;
}
