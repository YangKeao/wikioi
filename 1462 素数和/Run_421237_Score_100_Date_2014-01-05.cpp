#include<iostream>
#include<algorithm>
using namespace std;
int su(int x){//判定是否为素数 
    for(int i=2;i*i<=x;i++){
    	if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    int a,b;
    int n,sum=0;
    cin>>a>>b;
    if(a>b){int t;t=a;a=b;b=t;}
    if(a<=2) {
        sum+=2;
        a=3;//3是最小的质数 
    }
    for(int i=a;i<=b;i++){
        if(i%2==0) continue;
        if(i>10&&i%3==0) continue;
        if(su(i)) sum+=i;
    }
    cout<<sum;
    return 0;
}