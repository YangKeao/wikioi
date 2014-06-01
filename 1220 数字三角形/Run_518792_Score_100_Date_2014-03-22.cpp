#include <iostream>
using namespace std;
int n,s[110][110],f[110][110];
int t,g;
int main(){
    cin>>n;
    for(int i=1;i<=n-1;i++)
    for(int j=1;j<=i;j++)
    {
        cin>>s[i][j];
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>s[n][i];
        f[n][i]=s[n][i];
    }
    for(int i=n-1;i>=1;i--)
    for(int j=1;j<=i;j++)
    {
    	t=s[i][j]+f[i+1][j];
        g=s[i][j]+f[i+1][j+1];
        f[i][j]=t>g?t:g;
    }
    cout<<f[1][1];
	return 0;
}