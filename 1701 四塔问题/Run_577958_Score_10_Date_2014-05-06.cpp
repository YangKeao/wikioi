#include <iostream>
using namespace std;
int n;
long long f[50000];
long long b[50000];
long long mina=1111111111111;
int t;
int main(){
    cin>>n;
    f[1]=1;
    b[0]=1;
    for(int i=1;i<=n;i++)
    {
    	b[i]=b[i-1]*2;
    }
    for(int i=2;i<=n;i++)
    {
        mina=1111111;
    	for(int j=1;j<i;j++)
        {
        	t=2*f[j]+b[i-j]-1;
            if(t<mina) mina=t;
        }
        f[i]=mina;
    }
    cout<<f[n]%10000;
	return 0;
}