#include <iostream>
using namespace std;
int v;
int p;
int f[30001];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v>>p;
        for(int j=n;j>=v;j--)
        {
        	if(f[j-v]+v*p>f[j])
                f[j]=f[j-v]+v*p;
        }
    }
    cout<<f[n];
	return 0;
}