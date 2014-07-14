#include <iostream>
using namespace std;
long long n,c[1000000],a[1000000],qq[1000000],m,b;
long long t,g,l,k;
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
    	cin>>a[i];
    }
    cin>>m;
    for(long long i=1;i<=m;i++)
    {
    	cin>>t;
        if(t==1){
        	cin>>g>>l>>k;
            for(long long j=g;j<=l;j++) a[j]+=k;
        }
        else{
            cin>>g>>l;
            qq[b]=g;
            b=b+1;
            qq[b]=l;
            b++;
        }
    }
    for(long long i=1;i<=n;i++){
    	update(i,a[i]);
    }
    for(long long i=0;i<=b-1;i+=2){
    	cout<<sum(qq[i+1])-sum(qq[i]-1)<<endl;
    }
	return 0;
}
