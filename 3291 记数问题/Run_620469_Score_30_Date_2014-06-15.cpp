#include <iostream>
#include <string>
using namespace std;
int n,x,ans;
int t;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        for(int j=10;j<=i*10;j=j*10){
        	t=i*10/j;
            t=t%j;
            if(t==x) ans++;
        }
    }
    cout<<ans;
	return 0;
}