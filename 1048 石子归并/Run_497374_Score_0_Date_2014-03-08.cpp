#include <iostream>
// 1 2 3 4 
using namespace std;
int v[100][100],s[100];
int n,t,g;
int main(){
	cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>t;
        s[i]=s[i-1]+t;
        v[i][i]=0;
    }
    for(int i=n-1;i>0;i--)
    for(int j=i+1;j<=n;j++)
    for(int k=i;k<j;k++)
    {
    	t=v[i][k]+v[k+1][j]+s[j]-s[i-1];
        g=v[i][j];
        v[i][j]=t<g?t:g;
    }
    cout<<v[1][n];
    return 0;
}