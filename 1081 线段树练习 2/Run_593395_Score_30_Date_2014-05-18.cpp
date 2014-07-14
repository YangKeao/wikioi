#include <iostream>
using namespace std;
int a[200],n,m;
int t,f,g,h;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
    	cin>>t;
        if(t==1){
        	cin>>f>>g>>h;
            for(int i=f;i<=g;i++) a[i]+=h;
        }
        else {
            cin>>f;
        	cout<<a[f];
        }
    }
	return 0;
}