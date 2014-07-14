#include <iostream>
using namespace std;
int n,m;
bool t[100005];
int g;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>g;
        t[g]=1;
    }
    for(int i=1;i<=m;i++){
    	cin>>g;
        if(t[g]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0;
}