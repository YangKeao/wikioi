#include <iostream>
using namespace std;
long long n,c[1000000],m;
long long t,g,l,h;
long long low(long long x){
	return x&(-x);
}
long long sum(long long x){
	long long sum=0;
    while(x>0){
    	sum+=c[x];
        x-=low(x);
    }
    return sum;
}
long long update(long long x,long long y){
    while(x<=n){
    	c[x]+=y;
        x+=low(x);
    }
}
int main(){
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
    	cin>>t;
        update(i,t);
    }
    cin>>m;
    for(long long i=1;i<=m;i++)
    {
    	cin>>t;
        if(t==1){
            cin>>g>>l>>h;
        	for(long long i=g;i<=l;i++) update(i,h);
        }
        else{
            cin>>g>>l;
        	cout<<sum(l)-sum(g-1)<<endl;
        }
    }
	return 0;
}
