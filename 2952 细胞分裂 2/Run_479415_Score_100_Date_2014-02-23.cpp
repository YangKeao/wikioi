#include<iostream>
using namespace std;
long long a,q;
long long pow(long long b,long long p){
     if(p==1) return b%q;
     long long t;
     t=pow(b,p/2);
     if(p%2==0) return (t%q)*(t%q)%q;
     if(p%2==1) return ((t%q)*(t%q)*(b%q))%q;
}
int main()
{
    cin>>a>>q;
    cout<<pow(2,a);
    return 0;
}	
