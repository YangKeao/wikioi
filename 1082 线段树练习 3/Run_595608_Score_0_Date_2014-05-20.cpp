#include <iostream>
using namespace std;
int n,c[1000000],a[1000000],qq[1000000],m,b;
int t,g,l,k;
int low(int x){
	return x&(-x);
}
int sum(int x){
	int sum=0;
    while(x>0){
    	sum+=c[x];
        x-=low(x);
    }
    return sum;
}
int update(int x,int y){
    while(x<=n){
    	c[x]+=y;
        x+=low(x);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
    	cin>>t;
        if(t==1){
        	cin>>g>>l>>k;
            for(int j=g;j<=l;j++) a[j]+=k;
        }
        else{
            cin>>g>>l;
            qq[b]=g;
            b=b+1;
            qq[b]=l;
            b++;
        }
    }
    for(int i=1;i<=n;i++){
    	update(i,a[i]);
    }
    for(int i=0;i<=b-1;i+=2){
    	cout<<sum(qq[i+1])-sum(qq[i]-1)<<endl;
    }
	return 0;
}
