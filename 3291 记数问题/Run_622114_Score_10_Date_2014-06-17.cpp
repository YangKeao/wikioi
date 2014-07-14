#include <iostream>
#include <stdlib.h>
using namespace std;
int n,x,ans;
int t,j=1;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        while(i/j!=0){
        	if(j==1&&i==1) ans++;
        	else{
        		t=(i/j)%10;
        		if(t==x) ans++;
        	}
        	j*=10;
        }
        j=1;
    }
    cout<<ans;
	return 0;
}