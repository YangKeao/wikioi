#include<iostream>
using namespace std;
long long b,p,k;
long long pow(long long b,long long p){
     if(p==1) return b%k;
     long long t;
     t=pow(b,p/2);
     if(p%2==0) return (t%k)*(t%k)%k;
     if(p%2==1) return ((t%k)*(t%k)*(b%k))%k;
}
int main()
{
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"="<<pow(b,p);
    return 0;
}	
