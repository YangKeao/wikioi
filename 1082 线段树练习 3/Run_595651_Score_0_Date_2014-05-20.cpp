#include <iostream>
#include <stdio.h>
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
    scanf("%d",&n);
    for(long long i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(long long i=1;i<=m;i++)
    {
    	scanf("%d",&t);
        if(t==1){
        	scanf("%d%d%d",&g,&l,&k);
            for(long long j=g;j<=l;j++) a[j]=a[j]+k;
        }
        else{
            scanf("%d%d",&g,&l);
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
        printf("%d\n",sum(qq[i+1])-sum(qq[i]-1));
    }
	return 0;
}
