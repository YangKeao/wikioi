#include <iostream>
#include <algorithm>
using namespace std;
int n,m,d,ans;
int a[100];
int cmp(int a,int b){
	if(a>b) return 1;
	else return 0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    while(m>0){
    	m-=a[ans];
    	ans++;
    }
    cout<<--ans;
	return 0;
}