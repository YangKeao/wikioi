#include <iostream>
using namespace std;
int bone[10000],f[10000][10000];
int s,t,l,m;
int k;
int main(){
    cin>>l>>s>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>k;
        bone[k]=1;
    }
    for(int i=1;i<=l;i++)
    	if(bone[i]==1) f[i][i]=1;
    for(int i=1;i<=l;i++)
    for(int j=i+s;j<=i+t;j++)
    for(int k=j;;)
    {
    	
    }
    return 0;
}