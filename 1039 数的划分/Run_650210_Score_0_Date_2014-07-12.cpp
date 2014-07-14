#include <iostream>
#include <cstdio>
using namespace std;
double q;
int n,k,ans;
void go(int last,int sum,int num){
	if(num==k-2){
		ans=ans+(n-sum)/(k-num)-last;
	}
	else{
		for(int j=last;j<=(n-sum)/(k-num);j++){
			go(j,sum+j,num+1);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	q=n/k;
	for(int i=1;i<=q;i++)
		go(i,i,1);
	cout<<ans;
	return 0;
}