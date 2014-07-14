#include <iostream>
using namespace std;
int n,f[100][100],s[100];
int t,g;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        s[i]=s[i-1]+t;
        f[i][i]=0;
    }
    for(int i=n-1;i>=1;i--)
    for(int j=i+1;j<=n;j++)
    for(int k=i;k<=j;k++)
    {
    	t=f[i][k]+f[k+1][j]+s[j]-s[i-1];
        g=f[i][j];
        if(g>0)
        	f[i][j]=t<g?t:g;
        else
            f[i][j]=t;
    }
    cout<<f[1][n];
    return 0;
}
